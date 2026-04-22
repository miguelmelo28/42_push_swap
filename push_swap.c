/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/22 15:06:56 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder);
static int	adaptive(t_stack *a);
void		push_swap_run(t_stack **a, t_ops *ops, int *status);

int	push_swap(char **argv, int *status)
{
	t_stack	*a;
	t_ops	ops;

	a = NULL;
	ft_bzero(&ops, sizeof(t_ops));
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
	push_swap_run(&a, &ops, status);
	return (0);
}

void	push_swap_run(t_stack **a, t_ops *ops, int *status)
{
	int		complexity;
	double	disorder;

	ps_index_stack(*a);
	disorder = ps_disorder(*a);
	if (status[0] == 0)
		status[0] = 4;
	complexity = run_algorithm(a, ops, status[0], disorder);
	if (status[1] == 5)
		ps_print_benchmark(*ops, disorder, status[0], complexity);
	ps_stack_clear(a);
}

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder)
{
	int	complexity;

	if (algo == 4)
		complexity = adaptive(*a);
	else
		complexity = algo;
	if (disorder == 0)
		return (complexity);
	if (complexity == 1)
		min_extraction(a, ops);
	else if (complexity == 2)
		range_sort(a, ops);
	else if (complexity == 3)
		radix(a, ops);
	else if (complexity == 4)
		bad_sort(a, ops);
	return (complexity);
}

static int	adaptive(t_stack *a)
{
	int	size;
	int	complexity;

	size = total_data_size(a);
	if (total_data_size(a) <= 3)
		complexity = 4;
	else if (total_data_size(a) <= 5)
		complexity = 1;
	else if (total_data_size(a) <= 1100)
		complexity = 2;
	else
		complexity = 3;
	return (complexity);
}

// #include <stdio.h>
// static void	print_stack(t_stack *head)
// {
// 	int	pos;

// 	pos = 0;
// 	while (head)
// 	{
// 		printf("node[%d] -> num=%d, index=%d\n", pos, head->num, head->index);
// 		head = head->next;
// 		pos++;
// 	}
// }