/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:20:31 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:47:38 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *s)
{
	printf("%s\n");
	exit (1);
}

void	check_character(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error("Input includes a non-digit value");
			j++;
		}
		j = 0;
		i++;
	}
}
// argument_check returns 1 for single continous string otherwise 0.
// exits program with error messages in case of invalid prompt

int	argument_check(int argc, char **argv)
{
	check_character(argv);
	if (argc < 2)
		error("Please provide a list of integers.");
	else if (argc == 2)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*A;
	t_stack	*B;

	load_list(argv, argument_check(argc, argv), A, B);
	start_sort(A, B);
}