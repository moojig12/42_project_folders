/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:41:15 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:47:22 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_push(t_stack **stack, t_stack *cheapest, int mode)
{
	while (*stack != cheapest)
	{
		if (mode == 0)
		{
			if (cheapest->above_median == 1)
				rotate_a(stack);
			else if (cheapest->above_median == 0)
				reverse_a(stack);
		}
		else
		{
			if (cheapest->above_median == 1)
				rotate_b(stack);
			else
				reverse_b(stack);
		}
	}
}

void	calculate_costs_b(t_stack *A, t_stack *B)
{
	t_stack	*temp;
	int		i;
	int		median_a;
	int		median_b;

	i = 0;
	temp = A;
	median_a = list_size(A) / 2;
	median_b = list_size(B) / 2;
	while (temp)
	{
		temp->cost = temp->index;
		if (temp->above_median == 0)
			temp->cost = list_size(A) - temp->index;
		if (temp->target->above_median == 1)
			temp->cost += temp->target->index;
		else
			temp->cost += list_size(B) - temp->target->index;
		temp = temp->next;
	}
}

void	initiate_push_first(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*A);
	refresh_index(*A, *B);
	if (cheapest->above_median == 1)
		rotate_both(A, B, cheapest);
	else
		reverse_both(A, B, cheapest);
	refresh_index(*A, *B);
	prep_push(A, cheapest, 0);
	prep_push(B, cheapest->target, 1);
	push_b(A, B);
}

void	find_target_a(t_stack *A, t_stack *B)
{
	t_stack	*cursor_b;
	int		i;

	i = 0;
	while (A)
	{
		i = INT_MIN;
		cursor_b = B;
		while (cursor_b)
		{
			if (cursor_b->content < A->content \
			&& cursor_b->content > i)
			{
				A->target = cursor_b;
				i = cursor_b->content;
			}
			cursor_b = cursor_b->next;
		}
		if (i == INT_MIN)
			A->target = get_high(B);
		A = A->next;
	}
}
