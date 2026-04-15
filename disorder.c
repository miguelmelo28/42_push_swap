/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:42:16 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/15 12:38:08 by mmelo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	disorder(int *a, int len)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
		}
	}
	return ((double)mistakes / total_pairs);
}

// #include <stdio.h>
// int main(void)
// {
// 	int numbers[] = {1, 3, 2, 5, 9, 10};
// 	printf("%f\n", disorder(numbers, 6));
// }