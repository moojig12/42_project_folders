/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:39 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:48:26 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **dest, t_stack **origin)
{
	t_stack	**head_origin;
	t_stack	*new_head;

	if (!origin || !(*origin))
		return (1);
	// head_origin = origin;
	// new_head = *origin;
	// if (!dest || !*dest)
	// {
	// 	(*head_origin) = new_head->next;
	// 	new_head->next = NULL;
	// 	*dest = new_head;
	// }
	// else
	// {
	// 	(*head_origin) = new_head->next;
	// 	new_head->next = *dest;
	// 	(*head_origin)->prev = NULL;
	// 	*dest = new_head;
	// 	new_head->next->prev = new_head;
	// }
	return (0);
}

int	swap(t_stack **stack)
{
	printf("stack pointer: %p\n", *stack);
	return (0);
}

int	rotate(t_stack **stack)
{
	printf("stack pointer: %p\n", *stack);
	return (0);
}

int	reverse(t_stack **stack)
{
	printf("stack pointer: %p\n", *stack);
	return (0);
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
		printf("position %i: %i\n", i, temp->content);
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