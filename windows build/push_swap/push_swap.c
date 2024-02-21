/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 20:30:51 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
	{
		printf("list empty\n");
		return ;
	}
	while (stack)
	{
		i++;
		printf("position:%i | data:%i\n", i, stack->content);
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
		load_array(&A, argv);
	else
		load_list(&A, argc, argv);
	print_list(A);
	if (check_sort(A) == 0)
	{
		if (ft_lstsize((t_list *)A) <= 2)
		{
			printf("clause 1\n");
			short_sort(&A, &B);
		}
		else
		{
			printf("clause 2\n");
			nanni_sort(&A, &B);
		}
	}
	return (0);
}