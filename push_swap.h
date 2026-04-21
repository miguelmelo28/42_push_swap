/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/21 16:40:29 by mmelo         ########   odam.nl         */
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
void	bad_sort(t_stack **head, t_ops *ops);
void	radix(t_stack **head_a, t_ops *ops);
void	push_range_to_b(t_stack **head_a, t_stack **head_b,
	t_ops *ops, int range_size);
void	move_max_to_top(t_stack **head_b, t_ops *ops);
int		get_max_pos(t_stack *head);
int		get_range_size(int size);
int		get_stack_size(t_stack *head);
#endif