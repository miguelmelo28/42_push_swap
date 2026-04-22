/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 14:14:32 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/22 15:05:17 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_parse_int(const char *str, int *out);

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
		if (ps_parse_int(argv[i], &current_data))
		{
			ps_stack_clear(&a);
			return (NULL);
		}
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

static int	ps_parse_int(const char *str, int *out)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - '0');
		if ((sign == 1 && nb > 2147483647)
			|| (sign == -1 && (-nb) < -2147483648))
			return (1);
		i++;
	}
	*out = (int)(nb * sign);
	return (0);
}
