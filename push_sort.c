/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_sort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 13:06:53 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/15 16:19:01 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

	// size_t	pa;
	// size_t	pb;

	#include "push_swap.h"

	void	ps_push_b(t_stack **head_a, t_stack **head_b)
	{
		// make a tmp with current head
		// i need to delete the current head
		// tmp becomes head of b with ps_stackadd_front
		t_stack	*tmp;

		tmp = *head_a;
		*head_a = (*head)->next;
		ps_stackadd_front()
	}