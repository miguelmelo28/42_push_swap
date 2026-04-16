/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:08:10 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/16 14:57:31 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *ps_stack_second_last(t_stack *head)
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

void	rra(t_stack **head, t_ops *p)
{
	ps_rrotate(head);
	if (p)
		p->rra++;
}

void	rrb(t_stack **head, t_ops *p)
{
	ps_rrotate(head);
	if (p)
		p->rrb++;
}

void	rrr(t_stack **head_a, t_stack **head_b, t_ops *p)
{
	ps_rrotate(head_a);
	ps_rrotate(head_b);
	if (p)
		p->rrr++;
}