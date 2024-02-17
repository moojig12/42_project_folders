/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 14:42:25 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*A;
	t_stack	*B;

	A = NULL;
	B = NULL;
	if (argc == 2)
		A = array_load(argv);
	else
		A = list_load(argv, argc);
	if (!check_sort(A))
	{
		if (ft_lstsize <= 10)
			short_sort(&A, &B);
		else
			sort(&A, &B);
	}
	return (0);
}