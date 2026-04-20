/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 12:26:13 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder);

int	push_swap(char **argv, int *status)
{
	t_stack	*a;
	t_ops	ops;
	int		complexity;
	double	disorder;

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
	disorder = ps_disorder(a);
	complexity = run_algorithm(&a, &ops, status[0], disorder);
	if (status[1] == 5)
		ps_print_benchmark(ops, disorder, status[0], complexity);
	ps_stack_clear(&a);
	return (0);
}

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder)
{
	int complexity;

	if (algo == 4)
	{
		if (disorder < 0.2)
			complexity = 1;
		else if (disorder < 0.5)
			complexity = 2;
		else
			complexity = 3;
	}
	else
		complexity = algo;
	if (complexity == 1)
		min_extraction(a, ops);
	// else if (complexity == 2)
	// 	...(a, ops);
	else if (complexity == 3)
		radix(a, ops);
	return (complexity);
}