/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_algo_helper.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/21 11:38:11 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/22 15:03:09 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_range_to_b(t_stack **head_a, t_stack **head_b,
	t_ops *ops, int range_size)
{
	int	current_rank;

	current_rank = 0;
	while (*head_a)
	{
		if ((*head_a)->index <= current_rank)
		{
			pb(head_a, head_b, ops);
			if (get_stack_size(*head_b) > 1)
				rb(head_b, ops);
			current_rank++;
		}
		else if ((*head_a)->index <= current_rank + range_size)
		{
			pb(head_a, head_b, ops);
			current_rank++;
		}
		else
			ra(head_a, ops);
	}
}

void	move_max_to_top(t_stack **head_b, t_ops *ops)
{
	int	pos;
	int	size;

	pos = get_max_pos(*head_b);
	size = get_stack_size(*head_b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(head_b, ops);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(head_b, ops);
			pos++;
		}
	}
}

int	get_max_pos(t_stack *head)
{
	int	max;
	int	pos;
	int	i;

	max = head->index;
	pos = 0;
	i = 0;
	while (head)
	{
		if (head->index > max)
		{
			max = head->index;
			pos = i;
		}
		i++;
		head = head->next;
	}
	return (pos);
}

int	get_range_size(int size)
{
	int	num;

	num = 1;
	while (num * num < size)
		num++;
	return (num);
}

int	get_stack_size(t_stack *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
