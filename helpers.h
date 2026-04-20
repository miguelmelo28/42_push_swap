/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 13:00:37 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 10:49:27 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# include "push_swap.h"
# include "stack.h"
# include "operations.h"

int		ft_strcmp(const char *s1, const char *s2);
void	print_ops_or_emit(t_ops *ops, const char *name);
int		total_data_size(t_stack *head_local);
int		ps_validate_data(char **argv);
int		ps_duplicate_check(t_stack **head);
#endif