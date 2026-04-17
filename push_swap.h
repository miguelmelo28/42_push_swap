/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 13:01:26 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>

int		push_swap(char **argv, int *status);
void	min_extraction(t_stack **head_a, t_ops *ops);
double	disorder(int *a, int len);

#endif