/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 10:56:01 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "stack.h"
# include "operations.h"
# include "helpers.h"
# include <stdlib.h>

int		push_swap(char **argv, int *status);
double	ps_disorder(t_stack *head);
void	ps_print_benchmark(t_ops ops, double disorder, int strat, int comp);
void	ps_print_benchmark(t_ops ops, double disorder, int strat, int comp);
void	min_extraction(t_stack **head_a, t_ops *ops);
void	range_sort(t_stack **head_a, t_ops *ops);
void	radix(t_stack **head_a, t_ops *ops);

#endif