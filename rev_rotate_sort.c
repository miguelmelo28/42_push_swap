/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:08:10 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 15:52:57 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "helpers.h"

static t_stack	*ps_stack_second_last(t_stack *head)
{
	if (!head)
		return (NULL);
	if (!(head->next))
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

static void	ps_rrotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	last = ps_stacklast(*head);
	tmp = ps_stack_second_last(*head);
	last->next = (*head);
	*head = last;
	tmp->next = NULL;
}

void	rra(t_stack **head, t_ops *ops)
{
	ps_rrotate(head);
	if (ops)
	{
		ops->rra++;
		print_ops_or_emit(ops, "rra");
	}
}

void	rrb(t_stack **head, t_ops *ops)
{
	ps_rrotate(head);
	if (ops)
	{
		ops->rrb++;
		print_ops_or_emit(ops, "rrb");
	}
}

void	rrr(t_stack **head_a, t_stack **head_b, t_ops *ops)
{
	ps_rrotate(head_a);
	ps_rrotate(head_b);
	if (ops)
	{
		ops->rrr++;
		print_ops_or_emit(ops, "rrr");
	}
}
