/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:14:32 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 15:34:22 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	pw_stackadd_back(t_stack **lst, t_stack *new_node);
t_stack	*pw_stacknew(int num);
void	pw_stack_clear(t_stack **head);


t_stack	*pw_fill_stack(char **argv)
{
	t_stack	*a;
	t_stack	*new_node;
	int		current_data;
	int		i;

	a = NULL;
	i = 0;
	while(argv[i])
	{
		current_data = ft_atoi(argv[i]);
		new_node = pw_stacknew(current_data);
		if (!new_node)
		{
			pw_stack_clear(&a);
			return(NULL);
		}
		pw_stackadd_back(&a, new_node);
		i++;
	}
	return (a);
}
void	pw_stackadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*current;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

t_stack	*pw_stacknew(int num)
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

void	pw_stack_clear(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}