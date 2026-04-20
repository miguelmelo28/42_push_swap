/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 13:14:01 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_selected_strategy(t_stack **a, t_ops *ops, int *status,
				double *disorder);
static int	ps_is_sorted(t_stack *a);
static int	adaptive_sort(t_stack **a, t_ops *ops, double *disorder);

int	push_swap(char **argv, int *status)
{
	t_stack	*a;
	t_ops	ops;
	double	disorder;
	int		strategy;

	a = NULL;
	disorder = 0.0;
	strategy = 0;
	ft_bzero(&ops, sizeof(t_ops));
	if (status[0] == 5 || status[1] == 5)
		ops.bench = 1;
	if (ps_validate_data(argv))
		return (1);
	a = ps_fill_stack(argv);
	if (!a && argv[0] != NULL)
		return (1);
	if (ps_duplicate_check(&a))
	{
		ps_stack_clear(&a);
		return (1);
	}
	ps_index_stack(a);
	if (ps_is_sorted(a))
	{
		ps_stack_clear(&a);
		return (0);
	}
	if (ops.bench)
		disorder = disorder(a);
	strategy = run_selected_strategy(&a, &ops, status, &disorder);
	if (ops.bench)
		print_benchmark(ops, disorder, strategy);
	ps_stack_clear(&a);
	return (0);
}

static int	run_selected_strategy(t_stack **a, t_ops *ops, int *status,
	double *disorder)
{
	if (status[0] == 1 || status[1] == 1)
	{
		min_extraction(a, ops);
		return (1);
	}
	if (status[0] == 2 || status[1] == 2)
	{
		range_sort(a, ops);
		return (2);
	}
	if (status[0] == 3 || status[1] == 3)
	{
		radix_sort(a, ops);
		return (3);
	}
	return (adaptive_sort(a, ops, disorder));
}

static int	ps_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	adaptive_sort(t_stack **a, t_ops *ops, double *disorder)
{
	*disorder = compute_disorder(*a);
	if (*disorder < 0.2)
	{
		min_extraction(a, ops);
		return (1);
	}
	if (*disorder < 0.5)
	{
		range_sort(a, ops);
		return (2);
	}
	radix_sort(a, ops);
	return (3);
}