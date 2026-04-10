/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: stehoffm <stehoffm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/10 16:29:48 by stehoffm      #+#    #+#                 */
/*   Updated: 2026/04/10 17:49:49 by stehoffm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	status[2];

	status[0] = 0;
	status[1] = 0;
	if (argc < 2)
		//return error
	// give codes for bench being used and which algo 
	status[0] = check_algo_bench(argv[0]);
	status[1] = check_algo_bench(argv[1]);
	if (status[0] != 0 && status[1] != 0)
	{
		push_swap(argv + 3);
	}
	if (status[0] != 0)
		push_swap(argv + 2);
	push_swap(argv + 1);
	return (0);
}

char	**push_swap(int	count, char **argv)
{
	// convert the arguments to integers first (itoa)
	// store them on the stack in a
	// calculate the disorder
	// if simple, medium or complex send over to the apropriate algo
	// if advanced send over to advanced to decide which algorithm should be used
	// print the operations and the sorted data
	// if bench was used in cla print it
}
int	check_algo_bench(char *s)
{
	if (strncmp(s, "--simple", ft_strlen(s)))
		return (1)
	if (strncmp(s, "--medium", ft_strlen(s)))
		return (2);
	if (strncmp(s, "--complex", ft_strlen(s)))
		return (3);
	if (strncmp(s, "--adaptive", ft_strlen(s)))
		return (4);
	if (strncmp(s, "--bench", ft_strlen(s)))
		return (5);
	return (0);
}