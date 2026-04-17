/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 12:34:25 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv, int *status)
{
	t_stack	*a;
	t_ops	ops;

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
	if (status[0] == 1 || status[1] == 1 || status[0] == 0)
		min_extraction(&a, &ops);
	// if (ops.bench)
	// 	ps_print_bench(&ops);
	ps_stack_clear(&a);
	return (0);
}
