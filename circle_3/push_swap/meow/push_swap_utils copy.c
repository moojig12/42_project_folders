/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:39 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 15:26:36 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **origin)
{
	if (!origin || !*origin) // Check if origin stack is empty
		return;
		
	t_stack *node = *origin; // Extract the first node from origin stack
	*origin = (*origin)->next; // Update origin stack head

	if (*origin) // If origin stack is not empty after removal
		(*origin)->prev = NULL; // Update prev pointer of the new head to NULL

	// Connect the node to the destination stack
	node->prev = NULL; // Set prev pointer of node to NULL
	node->next = *dest; // Set next pointer of node to current head of destination stack

	if (*dest) // If destination stack is not empty
		(*dest)->prev = node; // Update prev pointer of current head of destination stack

	*dest = node; // Update destination stack head
	// t_stack	*node;

	// if (!origin || !*origin)
	// 	return ;
	// node = *origin;
	// *origin = (*origin)->next;
	// if (*origin)
	// 	(*origin)->prev = NULL;
	// node->prev = NULL;
	// if (!*dest)
	// {
	// 	*dest = node;
	// 	node->next = NULL;
	// }
	// else
	// {
	// 	node->next = *dest;
	// 	node->next->prev = node;
	// 	*dest = node;
	// }
}

void	swap(t_stack **stack)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
	return ;
}

void	reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*last;

	head = *stack;
	second = (*stack)->next;
	last = list_last(*stack);
	if (!second)
		return ;
	if (last == head)
	{
		*stack = head;
		head->prev = NULL;
	}
	else
	{
		last->next = head;
		head->prev = last;
		head->next = NULL;
		*stack = second;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*prev_last;

	head = *stack;
	if (list_size(*stack) < 2)
		return ;
	last = list_last(*stack);
	prev_last = last->prev;
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	head->prev = last;
	return ;
}

void	print_list(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (!stack)
	{
		ft_printf("list empty\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		ft_printf("position %i: %i\n", i, temp->content);
		i++;
		temp = temp->next;
	}
}

void	print_both(t_stack *A, t_stack *B)
{
	ft_printf("Stack A\n");
	print_list(A);
	ft_printf("Stack B\n");
	print_list(B);
}