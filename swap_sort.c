/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:06:16 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 12:28:53 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

int	sa(t_stack **head, t_ops *ops)
{
	t_stack	*tmp;

	tmp = *head;
	if (!(tmp->next))
		return (0);
	*head = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (ops)
	{
		ops->sa++;
		print_ops_or_emit(ops, "sa");
	}
	return (1);
}

int	sb(t_stack **head, t_ops *ops)
{
	t_stack	*tmp;

	tmp = *head;
	if (!(tmp->next))
		return (0);
	*head = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (ops)
	{
		ops->sb++;
		print_ops_or_emit(ops, "sb");
	}
	return (1);
}

int	ss(t_stack **head_a, t_stack **head_b, t_ops *ops)
{
	t_stack	*tmp;

	if (!((*head_a)->next) || !((*head_b)->next))
		return (0);
	tmp = *head_a;
	*head_a = tmp->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	tmp = *head_b;
	*head_b = tmp->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	if (ops)
	{
		ops->ss++;
		print_ops_or_emit(ops, "ss");
	}
	return (1);
}
