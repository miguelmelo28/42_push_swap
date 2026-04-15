/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 10:26:23 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 11:27:01 by stehoffm      ########   odam.nl         */
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
	size_t	total;
} t_ops;

typedef	struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
} t_stack;

int		push_swap(int argc, char **argv);
int		pw_check_algo_bench(char *s);
t_stack	*pw_fill_stack(char **argv);
int		validate_data(int argc, char **argv);
int		duplicate_check(int argc, char **argv);
void	pw_index_stack(t_stack *head);
double	disorder(int *a, int len);

#endif