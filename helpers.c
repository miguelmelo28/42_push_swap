/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/17 11:24:31 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/20 13:14:55 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "libft.h"

int	total_data_size(t_stack *head_local)
{
	int	i;

	i = 0;
	while (head_local)
	{
		head_local = head_local->next;
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_ops_or_emit(t_ops *ops, const char *name)
{
	if (!ops)
		return ;
	ft_putstr_fd((char *)name, 1);
	ft_putchar_fd('\n', 1);
}
