/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:33 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 17:44:53 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
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

void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	if (size_a-- > 3 && !check_sort(*A))
		push_b(A, B);
	if (size_a-- > 3 && !check_sort(*A))
		push_b(A, B);
	while (size_a-- > 3 && !check_sort(*A))
	{
		init_a_to_b(*A, *B);
		move_a_to_b(A, B);
	}
	if (!check_sort(*A))
		sort_three(A);
	while (*B)
	{
		init_a_to_b(*A, *B);
		move_b_to_a(A, B);
	}
	current_index(*A);
	last_sort(A);
}