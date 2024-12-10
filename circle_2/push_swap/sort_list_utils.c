/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:43:27 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 19:05:58 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_high(t_stack *stack)
{
	t_stack	*high;
	long	max;

	if (!stack)
		return (NULL);
	high = stack;
	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			high = stack;
		}
		stack = stack->next;
	}
	return (high);
}

t_stack	*get_low(t_stack *stack)
{
	long	min;
	t_stack	*low;

	if (!stack)
		return (NULL);
	min = stack->content;
	low = stack;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			low = stack;
		}
		stack = stack->next;
	}
	return (low);
}

int	check_sort(t_stack *stack)
{
	long	i;

	while (stack->next != NULL)
	{
		i = stack->content;
		if (i > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
