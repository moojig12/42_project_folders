/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:03:55 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 17:11:07 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target_a(t_stack *A, t_stack *B)
{
	t_stack	*target;
	t_stack	*current_a;
	long		target_value;

	if (!A || !B)
		return ;
	while (B)
	{
		target_value = LONG_MAX;
		current_a = A;
		// printf("Current node value: %i\n", B->content);
		while (current_a)
		{
			// printf("A->content: %i\n", current_a->content);
			if (current_a->content > B->content \
				&& current_a->content < target_value)
			{
				target_value = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target_value == LONG_MAX)
			B->target = get_low(A);
		else
			B->target = target;
		// printf("\nTarget set to: %i\n", B->target->content);
		B = B->next;
	}
}

void	init_b_to_a(t_stack *A, t_stack *B)
{
	current_index(A);
	current_index(B);
	find_target_a(A, B);
}

void	move_b_to_a(t_stack **A, t_stack **B)
{
	prep_push(A, (*B)->target, 'A');
	push_a(A, B);
}