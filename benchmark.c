/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmark.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:49:13 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 16:39:32 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// output must be stderr
#include "push_swap.h"

static void	print_disorder(double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	disorder *= 100;
	ft_putnbr_fd((int)disorder, 2);
	ft_putchar_fd('.', 2);
	disorder *= 10;
	ft_putnbr_fd((int)disorder % 10, 2);
	disorder *= 10;
	ft_putnbr_fd((int)disorder % 10, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_operations(t_ops ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(ops.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops.rrr, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_total_ops(t_ops ops)
{
	int	total_ops;

	total_ops = ops.sa + ops.sb + ops.ss + ops.pa + ops.pb + ops.ra + ops.rb
	+ ops.rr + ops.rra + ops.rrb + ops. rrr;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
}

static void print_strategy(int strategy, int complexity)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == 1)
		ft_putstr_fd("Simple / ", 2);
	else if (strategy == 2)
		ft_putstr_fd("Medium / ", 2);
	else if (strategy == 3)
		ft_putstr_fd("Complex / ", 2);
	else if (strategy == 4)
		ft_putstr_fd("Adaptive / ", 2);
	if (complexity == 1)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (complexity == 2)
		ft_putstr_fd("O(n sqrt(n))\n", 2);
	else if (complexity == 3)
		ft_putstr_fd("O(n log(n))\n", 2);
	else if (complexity == 4)
		ft_putstr_fd("O(n)\n", 2);
}

void	ps_print_benchmark(t_ops ops, double disorder, int strat, int comp)
{
	print_disorder(disorder);
	print_strategy(strat, comp);
	print_total_ops(ops);
	print_operations(ops);
}
