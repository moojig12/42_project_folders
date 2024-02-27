/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:15:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:09:32 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long	get_high(t_stack *stack)
{
	t_stack	*node;
	long		i;

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

long	get_low(t_stack *stack)
{
	t_stack	*node;
	long		i;

	node = stack;
	i = node->content;
	while (node->next)
	{
		node = node->next;
		if (node->content < i)
			i = node->content;
	}
	return (i);
}

int	check_sort_a(t_stack *stack)
{
	long i;

	while (stack->next != NULL)
	{
		i = stack->content;
		if (i > stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_sort_b(t_stack *stack)
{
	long i;

	while (stack->next != NULL)
	{
		i = stack->content;
		if (i < stack->next->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}