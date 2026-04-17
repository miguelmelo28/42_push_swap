/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_creation_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 15:09:57 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 11:24:25 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_stackadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*current;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_stack	*ps_stacknew(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ps_stack_clear(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	ps_stackadd_front(t_stack **head, t_stack *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}

t_stack	*ps_stacklast(t_stack *head_local)
{
	if (!head_local)
		return (NULL);
	while (head_local->next)
		head_local = head_local->next;
	return (head_local);
}
