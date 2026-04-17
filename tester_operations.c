/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/15 17:06:41 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/17 15:53:37 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "operations.h"
#include "helpers.h"

static void	print_stack(t_stack *head)
{
	int	pos;

	pos = 0;
	while (head)
	{
		printf("node[%d] -> num=%d, index=%d\n", pos, head->num, head->index);
		head = head->next;
		pos++;
	}
}

static void print_operations(t_ops o)
{
	printf("sa:%li\nsb:%li\nss:%li\nrra:%li\nrrb:%li\nrrr:%li\n", o.sa, o.sb, o.ss, o.rra, o.rrb, o.rrr);
}
static void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_ops operations = {0};

	if (argc < 2)
	{
		printf("Usage: ./tester_stack 3 1 2\n");
		return (1);
	}
	if (ps_validate_data(argv + 1))
	{
		printf("Validation failed\n");
		return (1);
	}
	a = ps_fill_stack(argv + 1);
	if (!a)
	{
		printf("Stack creation failed\n");
		return (1);
	}
	printf("Disorder: %f\n", disorder(a));
	ps_index_stack(a);
	printf("=== Stack after fill + index ===\n");
	print_stack(a);
	print_operations(operations);
	rra(&a, &operations);
	print_stack(a);
	print_operations(operations);
	free_stack(&a);
	return (0);
}