/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:50 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:53:19 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **stack, t_stack **node)
{
	t_stack	*push_node;

	if (node == NULL)
		return ;
	push_node = *node;
	*node = (*node)->next;
	if (*node)
		(*node)->prev = NULL;
	push_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack;
		push_node->next->prev = push_node;
		*stack = push_node;
	}
}

void	reverse(t_stack **stack)
{
	t_stack	*last;
	t_stack	*last_prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last_prev = last->prev;
	last_prev->next = NULL;
	last->next = (*stack);
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}
