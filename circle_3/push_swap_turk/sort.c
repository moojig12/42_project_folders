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

void	calculate_node_b()

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
		calculate_node_b(*A, *B);
		turk_b(A, B);
	}
	sort_three(A);
	while (*B)
	{
		calculate_node_a(*A, *B);
		turk_a(A, B);
	}
	current_index(*A);
	last_sort(A);
}