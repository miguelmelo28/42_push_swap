/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 17:55:48 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

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
} t_ops;

typedef	struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
} t_stack;

int		push_swap(int argc, char **argv);
int		ps_check_algo_bench(char *s);
t_stack	*ps_fill_stack(char **argv);
int		ps_validate_data(char **argv);
int		ps_duplicate_check(t_stack **head);
void	ps_index_stack(t_stack *head);
void	ps_stackadd_back(t_stack **head, t_stack *new_node);
t_stack	*ps_stacknew(int num);
void	ps_stack_clear(t_stack **head);
void 	ps_stackadd_front(t_stack **head, t_stack *new);
double	disorder(int *a, int len);
int	sa(t_stack **head, t_ops *operations);
int	ss(t_stack **head_a, t_stack **head_b, t_ops operations);
int	sb(t_stack **head, t_ops operations);

#endif