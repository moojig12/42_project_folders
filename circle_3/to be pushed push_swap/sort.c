/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:42 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:49:35 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	while (list_size(*A) > 3 && list_size(*B) < 2)
		push_b(A, B);
	while (--size_a > 4)
	{
		find_target_a(*A, *B);
		refresh_index(*A, *B);
		calculate_costs_b(*A, *B);
		set_cheapest(*A);
		initiate_push_first(A, B);
	}
	sort_three(A);
	while (list_size(*B) > 0)
	{
		find_target_b(*A, *B);
		initiate_push_second(A, B);
	}
	refresh_index(*A, *B);
	sort_min(A);
}

void	sort_min(t_stack **A)
{
	while (*A != get_low(*A))
	{
		if (get_low(*A)->above_median == 1)
			rotate_a(A);
		else
			reverse_a(A);
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
