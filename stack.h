/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 12:58:11 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/17 14:10:25 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "push_swap.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;
t_stack	*ps_fill_stack(char **argv);
void	ps_stackadd_back(t_stack **head, t_stack *new_node);
t_stack	*ps_stacknew(int num);
void	ps_stack_clear(t_stack **head);
void	ps_stackadd_front(t_stack **head, t_stack *new);
t_stack	*ps_stacklast(t_stack *head_local);
void	ps_index_stack(t_stack *head);
#endif