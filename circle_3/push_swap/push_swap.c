/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 17:48:36 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0
	while (stack->next != NULL)
	{
		printf("position:%i | data:%i", i, stack->content);
		i++;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*A;
	t_stack	*B;

	A = NULL;
	B = NULL;
	if (argc == 2)
		load_array(argv);
	else
		load_list(A, argc, argv);
	print_list(A);
	if (!check_sort(A))
	{
		if (ft_lstsize <= 10)
			short_sort(&A, &B);
		else
			sort(&A, &B);
	}
	return (0);
}