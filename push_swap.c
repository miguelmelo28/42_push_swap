/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/16 10:49:04 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	status[2];
	int	error;

	error = 0;
	status[0] = 0;
	status[1] = 0;
	if (argc < 2)
		ft_putstr_fd("Error\n", 2);
	status[0] = ps_check_algo_bench(argv[1]);
	status[1] = ps_check_algo_bench(argv[2]);
	if (status[0] != 0 && status[1] != 0)
	{
		error = push_swap(argv + 3);
	}
	else if (status[0] != 0)
		error = push_swap(argv + 2);
	else
		error = push_swap(argv + 1);
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

int	push_swap(char **argv)
{
	t_stack	*a;
	t_ops	p;

	ft_bzero(&p, sizeof(t_ops));
	if (ps_validate_data(argv))
		return (1);
	a = ps_fill_stack(argv);
	if (!a && argv[0] != NULL)
		return (1);
	if (ps_duplicate_check(&a))
		return (1);
	ps_index_stack(a);
	// calculate the disorder
	// if simple, medium or complex send over to the apropriate algo
	// if advanced send over to advanced to decide which algorithm should be used
	// print the operations and the sorted data
	// if bench was used in cla print it
	return(0);
}

int	ps_check_algo_bench(char *s)
{
	if (!ft_strcmp(s, "--simple"))
		return (1);
	if (!ft_strcmp(s, "--medium"))
		return (2);
	if (!ft_strcmp(s, "--complex"))
		return (3);
	if (!ft_strcmp(s, "--adaptive"))
		return (4);
	if (!ft_strcmp(s, "--bench"))
		return (5);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
