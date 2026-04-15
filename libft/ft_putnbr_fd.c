/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/18 10:34:32 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/03/19 12:06:20 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	putnbr((long)n, fd);
}

static void	putnbr(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
