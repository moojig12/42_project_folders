/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:15:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 20:07:45 by nmandakh         ###   ########.fr       */
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

t_stack	*get_high(t_stack *stack)
{
	t_stack	*high;
	long		i;

	if (!stack)
		return (NULL);
	high = stack;
	i = LONG_MIN;
	while (stack)
	{
		if (stack->content > i)
		{
			i = high->content;
			high = stack;
		}
		stack = stack->next;
	}
	return (high);
}

t_stack	*get_low(t_stack *stack)
{
	t_stack	*low;
	long		i;

	if (!stack)
		return (NULL);
	low = stack;
	i = LONG_MAX;
	while (stack)
	{
		if (stack->content < i)
		{
			i = low->content;
			low = stack;
		}
		stack = stack->next;
	}
	return (low);
}

int	check_sort(t_stack *stack)
{
	long i;

	while (stack->next != NULL)
	{
		i = stack->content;
		if (i > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	refresh_index(t_stack *A, t_stack *B)
{
	if (!A)
		return ;
	index_stack(A);
	if (!B)
		return ;
	index_stack(B);
}