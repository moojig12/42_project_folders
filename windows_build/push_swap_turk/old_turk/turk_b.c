/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:38:34 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 17:21:44 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_b(t_stack *A, t_stack *B)
{
	t_stack	*target;
	t_stack	*current_b;
	long		best_match;

	if (!A || !B)
		return ;
	target = NULL;
	while (A)
	{
		best_match = LONG_MIN;
		current_b = B;
		// printf("Current node A value: %i\n", A->content);
		while (current_b)
		{
			// printf("B->content: %i\n", current_b->content);
			if (current_b->content < A->content \
				&& current_b->content > best_match)
			{
				best_match = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			A->target = get_high(B);
		else
			A->target = target;
		// printf("\nTarget set to: %i\n", A->target->content);
		A = A->next;
	}
}

static void	find_cost_b(t_stack *A, t_stack *B)
{
	int	size_a;
	int	size_b;

	size_a = list_size(A);
	size_b = list_size(B);
	while (A)
	{
		A->cost = A->index;
		if (A->above_median == 0)
			A->cost = size_a - (A->index);
		if (A->target->above_median == 1)
			A->cost += A->target->index;
		else
			A->cost += size_b - (A->target->index);
		A = A->next;
	}
}

void	init_a_to_b(t_stack *A, t_stack *B)
{
	current_index(A);
	current_index(B);
	find_target_b(A, B);
	find_cost_b(A, B);
	set_cheapest(A);
}

static void	rev_rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target && *A != cheapest)
		reverse_r(A, B);
	current_index(*A);
	current_index(*B);
}

static void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target && *A != cheapest)
		rotate_r(A, B);
	current_index(*A);
	current_index(*B);
}

void	move_a_to_b(t_stack **A, t_stack **B)
{
	t_stack	*cheapest_node;
	
	cheapest_node = get_cheapest(*A);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(A, B, cheapest_node);
	else if (!(cheapest_node->above_median) \
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(A, B, cheapest_node);
	prep_push(A, cheapest_node, 'A');
	prep_push(B, cheapest_node->target, 'B');
	push_b(A, B);
}