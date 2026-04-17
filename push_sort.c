/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:06:53 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 12:09:24 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **head_a, t_stack **head_b, t_ops *p)
{
	t_stack	*tmp;

	if (!head_a || !head_b || !*head_a)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = NULL;
	ps_stackadd_front(head_b, tmp);
	if (p)
	{
		p->pb++;
		ps_emit_op(p, "pb");
	}
}

void	pa(t_stack **head_a, t_stack **head_b, t_ops *p)
{
	t_stack	*tmp;

	if (!head_b || !head_a || !*head_b)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = NULL;
	ps_stackadd_front(head_a, tmp);
	if (p)
	{
		p->pa++;
		ps_emit_op(p, "pa");
	}
}
