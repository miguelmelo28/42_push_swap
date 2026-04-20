/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium_algo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 10:48:16 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 12:56:11 by stehoffm      ########   odam.nl         */
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

static int	get_stack_size(t_stack *head)
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

static int	get_range_size(int size)
{
	int	num;

	num = 1;
	while (num * num < size)
		num++;
	return (num);
}

static void	push_range_to_b(t_stack **head_a, t_stack **head_b,
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

static void	move_max_to_top(t_stack **head_b, t_ops *ops)
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

static int	get_max_pos(t_stack *head)
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





