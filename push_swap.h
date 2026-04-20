/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 10:50:18 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "stack.h"
# include "operations.h"
# include "helpers.h"
# include <stdlib.h>
# include "stack.h"
# include "operations.h"
# include "helpers.h"

int		push_swap(char **argv, int *status);
void	min_extraction(t_stack **head_a, t_ops *ops);
double	disorder(t_stack *head);

#endif