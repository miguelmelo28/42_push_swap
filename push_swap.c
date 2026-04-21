/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 17:12:56 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder);
// static void	print_stack(t_stack *head);
static int adaptive(t_stack *a, double disorder);


int	push_swap(char **argv, int *status)
{
	t_stack	*a;
	t_ops	ops;
	int		complexity;
	int		strategy;
	double	disorder;

	a = NULL;
	disorder = 0.0;
	strategy = 0;
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
	ps_index_stack(a);
	// print_stack(a);
	disorder = ps_disorder(a);
	if (status[0] == 0)
		status[0] = 4;
	complexity = run_algorithm(&a, &ops, status[0], disorder);
	if (status[1] == 5)
		ps_print_benchmark(ops, disorder, status[0], complexity);
	// print_stack(a);
	ps_stack_clear(&a);
	return (0);
}

static int	run_algorithm(t_stack **a, t_ops *ops, int algo, double disorder)
{
	int complexity;

	if (algo == 4)
		complexity = adaptive(*a, disorder);
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
static int adaptive(t_stack *a, double disorder)
{
	int	complexity;

	if (disorder < 0.2)
		complexity = 1;
	else if (disorder < 0.5)
		complexity = 2;
	else
		complexity = 3;
	if (total_data_size(a) <= 3)
		complexity = 4;
	else if (total_data_size(a) <= 5)
		complexity = 1;
	else if (total_data_size(a) <= 100)
		complexity = 2;
	else if (total_data_size(a) <= 500)
		complexity = 2;
	else
		complexity = 3;
	return complexity;
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