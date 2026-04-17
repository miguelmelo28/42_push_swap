/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:07:52 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 12:28:45 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	last = ps_stacklast(*head);
	*head = (*head)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **head, t_ops *ops)
{
	ps_rotate(head);
	if (ops)
	{
		ops->ra++;
		print_ops_or_emit(ops, "ra");
	}
}

void	rb(t_stack **head, t_ops *ops)
{
	ps_rotate(head);
	if (ops)
	{
		ops->rb++;
		print_ops_or_emit(ops, "rb");
	}
}

void	rr(t_stack **head_a, t_stack **head_b, t_ops *ops)
{
	ps_rotate(head_a);
	ps_rotate(head_b);
	if (ops)
	{
		ops->rr++;
		print_ops_or_emit(ops, "rr");
	}
}
