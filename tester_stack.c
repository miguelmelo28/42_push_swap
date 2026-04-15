#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

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

/*
static void	print_stack(t_stack *head)
{
	int	pos;

	pos = 0;
	while (head)
	{
		printf("node[%d] @ %p -> num=%d, index=%d, next=%p\n",
			pos, (void *)head, head->num, head->index, (void *)head->next);
		head = head->next;
		pos++;
	}
}
*/

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
	ps_index_stack(a);
	printf("=== Stack after fill + index ===\n");
	print_stack(a);
	free_stack(&a);
	return (0);
}