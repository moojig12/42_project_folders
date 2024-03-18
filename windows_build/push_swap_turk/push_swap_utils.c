/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:11:05 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 20:26:27 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	print_list(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (!stack)
	{
		printf("list empty\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		printf("position: %i\n%i\n", i, temp->content);
		printf("cost: %i\n", temp->cost);
		printf("target: %i\n", stack->target->content);
		printf("\n");
		i++;
		temp = temp->next;
	}
}

void	print_both(t_stack *A, t_stack *B)
{
	printf("Stack A\n");
	print_list(A);
	printf("Stack B\n");
	print_list(B);
}