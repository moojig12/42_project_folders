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

void	load_list(char **argv, int mode, t_stack **A, t_stack **B)
{
	int	i;

	i = 0;
	// while loop for loading elements
}

int	argument_check(int argc, char **argv)
{
	// check if there is given argument
	// check if continuous string or multiple arguments
	// check if there is any character in argv
	// check if there are doubles
	// check for INT_MAX and INT_MIN
	// if there is any error return -1
	// otherwise return 1 for string and return 0 for number of lists
}

int	main(int argc, char **argv)
{
	t_stack	*A;
	t_stack	*B;

	load_list(argv, argument_check(argc, argv), A, B);
	start_sort(A, B);
}