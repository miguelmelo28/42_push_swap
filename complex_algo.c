/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 16:02:46 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/20 13:01:55 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "stack.h"
#include "operations.h"

int	n_digits(t_stack *head)
{
	int	digits;
	int	max_index;

	digits = 0;
	max_index = total_data_size(head) - 1;
	while (max_index)
	{
		max_index /= 2;
		digits++;
	}
	return (digits);
}

void	pa_all(t_stack **head_a, t_stack **head_b, t_ops *ops)
{
	while (*head_b)
		pa(head_a, head_b, ops);
}

void	radix(t_stack **head_a, t_ops *ops)
{
	int		bit;
	int		digits;
	int		data_ammount;
	t_stack	*head_b;

	digits = n_digits(*head_a);
	bit = -1;
	head_b = 0;
	while (++bit < digits)
	{
		data_ammount = total_data_size(*head_a);
		while (data_ammount--)
		{
			if (((*head_a)->index >> bit) & 1)
				ra(head_a, ops);
			else
				pb(head_a, &head_b, ops);
		}
		pa_all(head_a, &head_b, ops);
	}
}
