/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:25:13 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 10:36:28 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pw_index_stack(t_stack *head)
{
	t_stack	*cur;
	t_stack	*other;
	int		rank;

	cur = head;
	while (cur)
	{
		rank = 0;
		other = head;
		while (other)
		{
			if (other->num < cur->num)
				rank++;
			other = other->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}
