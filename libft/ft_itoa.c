/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/18 10:25:57 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/03/18 10:28:02 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long n);
static void	fill_string(char *s, long n, int counter, int sign);

char	*ft_itoa(int n)
{
	char	*converted;
	int		counter;
	int		sign;
	long	nb;

	nb = n;
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = 1;
	}
	counter = count_digit(nb);
	if (sign == 1)
		converted = malloc((counter + 2) * sizeof(char));
	else
		converted = malloc((counter + 1) * sizeof(char));
	if (!converted)
		return (0);
	fill_string(converted, nb, counter + sign, sign);
	return (converted);
}

static int	count_digit(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	fill_string(char *s, long n, int counter, int sign)
{
	s[counter] = '\0';
	while (counter > sign)
	{
		s[counter - 1] = n % 10 + '0';
		n /= 10;
		counter--;
	}
	if (sign == 1)
		s[0] = '-';
}
