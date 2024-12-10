/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:15:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:48:32 by nmandakh         ###   ########.fr       */
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

void	index_stack(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = list_size(stack) / 2;
	while (stack)
	{
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack->index = i;
		i++;
		stack = stack->next;
	}
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
