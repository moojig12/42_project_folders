/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:44:15 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:45:00 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_push_second(t_stack **A, t_stack **B)
{
	refresh_index(*A, *B);
	prep_push(A, (*B)->target, 0);
	push_a(A, B);
}

void	find_target_b(t_stack *A, t_stack *B)
{
	t_stack	*cursor_a;
	int		i;

	while (B)
	{
		i = INT_MAX;
		cursor_a = A;
		while (cursor_a)
		{
			if (cursor_a->content > B->content \
			&& cursor_a->content < i)
			{
				B->target = cursor_a;
				i = cursor_a->content;
			}
			cursor_a = cursor_a->next;
		}
		if (i == INT_MAX)
			B->target = get_low(A);
		B = B->next;
	}
}

void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target && *A != cheapest)
		rotate_r(A, B);
}

void	reverse_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target && *A != cheapest)
		reverse_r(A, B);
}
