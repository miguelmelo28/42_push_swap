/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   low_disorder_algo.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/21 13:17:17 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/22 15:32:46 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_wrong_rank(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index != i)
			break ;
		i++;
		head = head->next;
	}
	return (head->index);
}

void	rotate_rank(t_stack **head, t_ops *ops, int rank)
{
	int		index;
	t_stack	*current;
	int		size;

	size = total_data_size(*head);
	index = 0;
	current = *head;
	while (current)
	{
		if (current->index == rank)
			break ;
		index++;
		current = current->next;
	}
	if (index > size / 2)
		while (index++ - size)
			rra(head, ops);
	else
		while (index--)
			ra(head, ops);
}

void	fix_rank(t_stack **head, t_ops *ops, int rank)
{
	rotate_rank(head, ops, rank);
	while (1)
	{
		sa(head, ops);
		if ((*head)->index + 1 == (*head)->next->index)
			break ;
		else
			ra(head, ops);
	}
}

void	bad_sort(t_stack **head, t_ops *ops)
{
	int	rank;

	rotate_rank(head, ops, 0);
	while (ps_disorder(*head))
	{
		rank = find_wrong_rank(*head);
		fix_rank(head, ops, rank);
		rotate_rank(head, ops, 0);
	}
}
