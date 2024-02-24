/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:36:46 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 16:36:55 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	insert_node(t_stack **stack, t_stack *node)
{
	if (!node)
		error("Null node attempted to insert");
	if (!stack || !*stack)
		*stack = node;
	else
	{
		(*stack)->next = node;
		node->prev = (*stack);
		*stack = node;
	}
	return ;
}

int	list_size(t_stack *stack)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = stack;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	get_high(t_stack *stack)
{
	t_stack	*node;
	int		i;

	node = stack;
	i = node->content;
	while (node->next)
	{
		node = node->next;
		if (node->content > i)
			i = node->content;
	}
	return (i);
}

int	check_sort(t_stack *stack)
{
	int i;

	while (stack->next != NULL)
	{
		i = stack->content;
		if (i < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*list_last(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}