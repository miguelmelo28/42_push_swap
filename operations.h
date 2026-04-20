/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 17:11:17 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/17 14:10:53 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "push_swap.h"

typedef struct s_ops
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	int		bench;
}	t_ops;
void	pb(t_stack **head_a, t_stack **head_b, t_ops *ops);
void	pa(t_stack **head_a, t_stack **head_b, t_ops *ops);
void	ra(t_stack **head, t_ops *ops);
void	rb(t_stack **head, t_ops *ops);
void	rr(t_stack **head_a, t_stack **head_b, t_ops *ops);
int		sa(t_stack **head, t_ops *ops);
int		sb(t_stack **head, t_ops *ops);
int		ss(t_stack **head_a, t_stack **head_b, t_ops *ops);
void	rra(t_stack **head, t_ops *ops);
void	rrb(t_stack **head, t_ops *ops);
void	rrr(t_stack **head_a, t_stack **head_b, t_ops *ops);
#endif