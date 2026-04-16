/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmelo <mmelo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/27 14:42:16 by mmelo         #+#    #+#                 */
/*   Updated: 2026/04/16 10:43:11 by stehoffm      ########   odam.nl         */
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
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}
