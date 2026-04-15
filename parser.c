/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:14:32 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 16:17:52 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*ps_fill_stack(char **argv)
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
		new_node = ps_stacknew(current_data);
		if (!new_node)
		{
			ps_stack_clear(&a);
			return(NULL);
		}
		ps_stackadd_back(&a, new_node);
		i++;
	}
	return (a);
}
