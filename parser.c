/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:14:32 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 10:33:06 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make sure to only take in up to INT_MIN / INT_MAX!

t_stack	*ps_fill_stack(char **argv)
{
	t_stack	*a;
	t_stack	*new_node;
	int		current_data;
	int		i;

	a = NULL;
	i = 0;
	while (argv[i])
	{
		current_data = ft_atoi(argv[i]);
		new_node = ps_stacknew(current_data);
		if (!new_node)
		{
			ps_stack_clear(&a);
			return (NULL);
		}
		ps_stackadd_back(&a, new_node);
		i++;
	}
	return (a);
}
