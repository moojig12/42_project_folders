/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 17:39:34 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		i++;
		printf("position:%i | data:%i\n", i, stack->content);
		stack = stack->next;
	}
}

void	load_array(char **argv)
{
	printf("%s\n", argv[0]);
	return ;
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
		if (ft_lstsize((t_list *)A) <= 10)
		{
			printf("clause 1\n");
			short_sort(&A, &B);
		}
		else
		{
			printf("clause 2\n");
			sort(&A, &B);
		}
	}
	return (0);
}