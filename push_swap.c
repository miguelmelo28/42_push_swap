/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 16:52:32 by mmelo         ########   odam.nl         */
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
		//return error
	// give codes for bench being used and which algo 
	status[0] = pw_check_algo_bench(argv[1]);
	status[1] = pw_check_algo_bench(argv[2]);
	if (status[0] != 0 && status[1] != 0)
	{
		error = push_swap(argc - 3, argv + 3);
	}
	else if (status[0] != 0)
		error = push_swap(argc - 2, argv + 2);
	error = push_swap(argc - 1, argv + 1);
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

int	push_swap(char **argv)
{
	t_stack	*a;

	if (validate_data(argv))
		return (1);
	a = pw_fill_stack(argv);
	if (!a && argv[0] != NULL)
		return (1);
	if (duplicate_check(&a))
		return (1);
	pw_index_stack(a);
	// convert the arguments to integers first (itoa)
	// store them on the stack in a
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