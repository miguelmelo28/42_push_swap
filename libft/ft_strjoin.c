/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/18 10:42:13 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/03/19 12:08:59 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fill_string(char *ptr, const char *s, size_t loc_ptr);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*new_string;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = malloc(s1_len + s2_len + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	i = fill_string(new_string, s1, 0);
	i = fill_string(new_string, s2, i);
	new_string[i] = '\0';
	return (new_string);
}

static size_t	fill_string(char *ptr, const char *s, size_t loc_ptr)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ptr[loc_ptr] = s[i];
		i++;
		loc_ptr++;
	}
	return (loc_ptr);
}
