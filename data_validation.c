/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 09:58:25 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 11:36:03 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_data(int argc, char **argv)
{
	int	i;
	int	j;

	(void) argc;
	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
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
/*
int	duplicate_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}*/