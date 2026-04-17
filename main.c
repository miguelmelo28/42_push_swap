/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 12:26:05 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 12:26:06 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_is_algo_flag(int status);
static int	ps_invalid_flag_combo(int s0, int s1);
static int	ps_run_with_flags(char **argv, int *status);
static int ps_check_algo_bench(char *s); 

int	main(int argc, char **argv)
{
	int	status[2];
	int	error;

	status[0] = 0;
	status[1] = 0;
	if (argc < 2)
		return (0);
	if (argc > 1)
		status[0] = ps_check_algo_bench(argv[1]);
	if (argc > 2)
		status[1] = ps_check_algo_bench(argv[2]);
	if (ps_invalid_flag_combo(status[0], status[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	error = ps_run_with_flags(argv, status);
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
	return (0);
}
static int ps_check_algo_bench(char *s) 
{ 
	if (!ft_strcmp((const char *)s, "--simple"))
		return (1);
	if (!ft_strcmp((const char *)s, "--medium"))
		return (2);
	if (!ft_strcmp((const char *)s, "--complex"))
		return (3);
	if (!ft_strcmp((const char *)s, "--adaptive"))
		return (4);
	if (!ft_strcmp((const char *)s, "--bench"))
	return (5); return (0);
}
static int	ps_is_algo_flag(int status)
{
	return (status >= 1 && status <= 4);
}

static int	ps_invalid_flag_combo(int s0, int s1)
{
	if (ps_is_algo_flag(s0) && ps_is_algo_flag(s1))
		return (1);
	if (s0 == 5 && s1 == 5)
		return (1);
	return (0);
}
static int	ps_run_with_flags(char **argv, int *status)
{
	if (status[0] != 0 && status[1] != 0)
		return (push_swap(argv + 3, status));
	if (status[0] != 0)
		return (push_swap(argv + 2, status));
	return (push_swap(argv + 1, status));
}
