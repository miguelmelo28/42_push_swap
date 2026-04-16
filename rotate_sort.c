/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:07:52 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/16 09:38:32 by stehoffm      ########   odam.nl         */
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

void	ra(t_stack **head, t_ops *p)
{
	ps_rotate(head);
	if (p)
		p->ra++;
}

void	rb(t_stack **head, t_ops *p)
{
	ps_rotate(head);
	if (p)
		p->rb++;
}

void	rr(t_stack **head_a, t_stack **head_b, t_ops *p)
{
	ps_rotate(head_a);
	ps_rotate(head_b);
	if (p)
		p->rr++;
}
