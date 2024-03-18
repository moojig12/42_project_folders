/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:42 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 20:33:12 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	//	push 2 elements to B
	while (list_size(*A) > 3 && list_size(*B) <= 2)
		push_b(A, B);
	sort_three(B);
	//	initiate first part
	while (--size_a > 3)
	{
		find_target_a(*A, *B);	//		calculate costs
		calculate_costs(*A, *B);
		// initiate_push_first(A, B);	//		operate according to costs
	}
	sort_three(A);	// sort remaining A nodes

	//	initiate second part
	/* while (list_size(*B) > 0)
	{
		find_target_b(*A, *B);
		// calculate_costs_b(*A, *B);
		initiate_push_second(A, B);
	} */
	
	// refresh_index(*A, *B);
	// sort_min(A);
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = list_size(stack);
	while (stack)
	{
		if (i > median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}

void	resfresh_index(t_stack *A, t_stack *B)
{
	index_stack(A);
	index_stack(B);
}

void	find_target_a(t_stack *A, t_stack *B)
{
	t_stack	*cursor_b;
	int		i;

	i = 0;
	//	start while loop for each node
	while (A)
	{
		i = A->content;
		cursor_b = B;
		while (cursor_b)
		{
			ft_printf("B >? A: %i | %i\n", cursor_b->content, A->content);
			if (cursor_b->content < A->content \
			&& cursor_b->content > i) // if node is smaller than A and bigger than last target
			{
				A->target = cursor_b;
				i = cursor_b->content;
				ft_printf("target: %i\n", A->target->content);
			}
			cursor_b = cursor_b->next;
		}
		if (i == A->content)
			A->target-> = get_high(B);
		A = A->next;
	}
}

void	find_target_b(t_stack *A, t_stack *B)
{
	t_stack	*cursor_a;
	int		i;

	i = 0;
	//	start while loop for each node
	while (B)
	{
		i = B->content;
		cursor_a = A;
		while (cursor_a)
		{
			if (cursor_a->content > B->content \
			&& cursor_a->content < i) // find smallest and closest number to A node
			{
				B->target = cursor_a;
				i = cursor_a->content;
			}
			cursor_a = cursor_a->next;
		}
		if (i == A->content)
			B->target = get_low(A);
		B = B->next;
	}
}

void	calculate_costs(t_stack *A, t_stack *B)
{
	int	i;
	int	median_a;
	int	median_b;

	i = 0;
	median_a = list_size(A) / 2;
	median_b = list_size(B) / 2;
	while (A)
	{
		if (A->above_median == 1)
		{
			A->cost = i;
		}
		else
		{
			A->cost = list_size(A) - i;
		}
		i++;
		A = A->next;
	}
}

/* void	initiate_push_first(t_stack **A, t_stack *B)
{
	// rotate lowest cost to first node
	// push
} */
