/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_algo.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 10:45:51 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 11:31:48 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	upper_stack(t_stack **head_a, t_stack **head_b, t_ops *ops, int rotations);
static void	lower_stack(t_stack **head_a, t_stack **head_b, t_ops *ops, int rotations);
static void	push_to_sort(t_stack **head_a, t_stack **head_b, t_ops *ops);
static int	find_target_pos(t_stack *head, int target);

void	min_extraction(t_stack **head_a, t_ops *ops)
{
	t_stack	*head_b;
	int		current_target;
	int		pos;
	int		size;

	head_b = NULL;
	current_target = 0;
	while (total_data_size(*head_a) > 1)
	{
		size = total_data_size(*head_a);
		pos = find_target_pos(*head_a, current_target);
		if (pos <= size / 2)
			upper_stack(head_a, &head_b, ops, pos);
		else
			lower_stack(head_a, &head_b, ops, size - pos);
		current_target++;
	}
	push_to_sort(head_a, &head_b, ops);
}

static void	upper_stack(t_stack **head_a, t_stack **head_b, t_ops *ops, int rotations)
{
	while (rotations > 0)
	{
		ra(head_a, ops);
		rotations--;
	}
	pb(head_a, head_b, ops);
}

static void	lower_stack(t_stack **head_a, t_stack **head_b, t_ops *ops, int rotations)
{
	while (rotations > 0)
	{
		rra(head_a, ops);
		rotations--;
	}
	pb(head_a, head_b, ops);
}

static void	push_to_sort(t_stack **head_a, t_stack **head_b, t_ops *ops)
{
	while (*head_b)
		pa(head_a, head_b, ops);
}

static int	find_target_pos(t_stack *head, int target)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->index == target)
			return (pos);
		head = head->next;
		pos++;
	}
	return (-1);
}