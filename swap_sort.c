/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:06:16 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 15:46:06 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

	// size_t	sa;
	// size_t	sb;
	// size_t	ss;

#include "push_swap.h"
#include "unistd.h"

int sa(t_stack **head, t_ops operations)
{
	t_stack	*tmp;

	tmp = *head;
	if (!(tmp->next))
		return (0);
	*head = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	write(1, "sa\n", 3);
	operations.sa++;
	return (1);
}

int sb(t_stack **head, t_ops operations)
{
	t_stack	*tmp;

	tmp = *head;
	if (!(tmp->next))
		return (0);
	*head = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	write(1, "sb\n", 3);
	operations.sb++;
	return (1);
}

int ss(t_stack **head_a, t_stack **head_b, t_ops operations)
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
	write(1, "ss\n", 3);
	operations.ss++;
	return (1);
}
