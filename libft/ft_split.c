/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/18 10:35:55 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/03/19 14:51:18 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strings(char const *s, char c);
static size_t	ft_strlen_mod(char const *s, char c);
static char		**fill_split(char **new_strings, char const *s, char c);
void			split_free(char **new_strings, size_t j);

char	**ft_split(char const *s, char c)
{
	char	**new_strings;
	size_t	string_amount;

	if (!s)
		return (NULL);
	string_amount = count_strings(s, c);
	new_strings = malloc((string_amount + 1) * sizeof(char *));
	if (!new_strings)
		return (NULL);
	return (fill_split(new_strings, s, c));
}

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static size_t	ft_strlen_mod(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**fill_split(char **new_strings, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len_strs;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len_strs = ft_strlen_mod(s + i, c);
			new_strings[j] = ft_substr(s, i, len_strs);
			if (!new_strings[j])
			{
				split_free(new_strings, j);
				return (NULL);
			}
			j++;
			i += len_strs;
		}
	}
	new_strings[j] = NULL;
	return (new_strings);
}

void	split_free(char **new_strings, size_t j)
{
	while (j > 0)
		free(new_strings[--j]);
	free(new_strings);
}
