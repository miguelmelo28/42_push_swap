/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:42:16 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/17 19:07:24 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

double	disorder(t_stack *head)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*current;
	t_stack	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = head;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->num > compare->num)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)mistakes / total_pairs);
}
