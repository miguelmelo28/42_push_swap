/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 09:58:25 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/16 10:42:30 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_validate_data(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (1);
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit((unsigned char)argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ps_duplicate_check(t_stack **head)
{
	t_stack	*cur;
	t_stack	*other;

	cur = *head;
	while (cur)
	{
		other = cur->next;
		while (other)
		{
			if (other->num == cur->num)
				return (1);
			other = other->next;
		}
		cur = cur->next;
	}
	return (0);
}
