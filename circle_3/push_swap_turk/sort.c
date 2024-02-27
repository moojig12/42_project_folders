/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:33 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:12:45 by nmandakh         ###   ########.fr       */
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

void	start_b_push(t_stack **A, t_stack **B)
{
	while (list_size(*A) > 3)
	{
		find_target(A, B);
		calculate_cost(*A, *B);
		do_op(A, B);
	}
}

void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	if (list_size(*A) > 3 && !check_sort_a(*A))
		push_b(A, B);
	if (list_size(*A) > 3 && !check_sort_a(*A))
		push_b(A, B);
	while (list_size(*A) > 3 && !check_sort_a(*A))
	{
		calculate_node(*A, *B);
		turk_a_to_b(A, B);
	}
	sort_three(A);
	while (*B)
	{
		calculate_node(*A, *B);
		turk_b_to_a(A, B);
	}
	current_index(*A);
	last_sort(A);
}