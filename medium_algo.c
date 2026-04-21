/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_algo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 10:48:16 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 11:42:20 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort(t_stack **head_a, t_ops *ops)
{
	t_stack	*head_b;
	int		size;
	int		range_size;

	if (!head_a || !*head_a)
		return ;
	head_b = NULL;
	size = get_stack_size(*head_a);
	range_size = get_range_size(size);
	push_range_to_b(head_a, &head_b, ops, range_size);
	while (head_b)
	{
		move_max_to_top(&head_b, ops);
		pa(head_a, &head_b, ops);
	}
}
