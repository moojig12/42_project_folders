/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:26:42 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 16:30:28 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	//	push 2 elements to B
	while (list_size(*A) > 3 && list_size(*B) < 2)
		push_b(A, B);
	// sort_three(B);
	//	initiate first part
	while (size_a-- > 3)
	{
		find_target_a(*A, *B);	//		calculate costs
		refresh_index(*A, *B);
		calculate_costs(*A, *B);
		print_both(*A, *B);
		// initiate_push_first(A, B);
	}
	/* sort_three(A);	// sort remaining A nodes
	print_both(*A, *B);

	while (list_size(*B) > 0)
	{
		find_target_b(*A, *B);
		// calculate_costs_b(*A, *B);
		initiate_push_second(A, B);
	}
	refresh_index(*A, *B);
	sort_min(A); */
}

/* void	refresh_index(t_stack *A, t_stack *B)
{
	index_stack(A);
	index_stack(B);
} */

void	find_target_a(t_stack *A, t_stack *B)
{
	t_stack	*cursor_b;
	int		i;

	i = 0;
	//	start while loop for each node
	while (A)
	{
		i = INT_MIN;
		cursor_b = B;
		while (cursor_b)
		{
			if (cursor_b->content < A->content \
			&& cursor_b->content > i) // if node is smaller than A and bigger than last target
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

void	find_target_b(t_stack *A, t_stack *B)
{
	t_stack	*cursor_a;
	int		i;

	i = 0;
	//	start while loop for each node
	while (B)
	{
		i = INT_MAX;
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
		if (i == INT_MAX)
			B->target = get_low(A);
		B = B->next;
	}
}

void	calculate_costs(t_stack *A, t_stack *B)
{
	t_stack	*temp;
	int	i;
	int	median_a;
	int	median_b;

	i = 0;
	temp = A;
	median_a = list_size(A) / 2;
	median_b = list_size(B) / 2;
	while (temp)
	{
		if (temp->target->index <= median_b)
			temp->target->cost = temp->target->index;
		else
			temp->target->cost = temp->target->index - list_size(B);
		if (i <= median_a)
			temp->cost = temp->index + temp->target->cost;
		else
			temp->cost = temp->index - list_size(A);
		i++;
		temp = temp->next;
	}
}

void	prep_push(t_stack **stack, t_stack *cheapest, int mode)
{
	while (*stack != cheapest)
	{
		if (mode == 0)
		{
			// ft_printf("%i", cheapest->content);
			if (cheapest->above_median == 1)
				rotate_a(stack);
			else if (cheapest->above_median == 0)
				reverse_a(stack);	
		}
		else
		{
			// ft_printf("%i, %i", cheapest->content, cheapest->above_median);
			if (cheapest->above_median == 1)
				rotate_b(stack);
			else
				reverse_b(stack);	
		}
	}
}

void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target
		&& *A != cheapest) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rotate_r(A, B); //Rotate both `a` and `b` nodes
	refresh_index(*A, *B);
}

void	reverse_both(t_stack **A, t_stack **B, t_stack *cheapest)
{
	while (*B != cheapest->target
		&& *A != cheapest) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
		reverse_r(A, B);
	refresh_index(*A, *B);
}

void	initiate_push_first(t_stack **A, t_stack **B)
{
	t_stack	*cheapest;

	
	cheapest = set_cheapest(*A);
	// rotate lowest cost to first node
	if (cheapest->above_median == 1)
		rotate_both(A, B, cheapest);
	else
		reverse_both(A, B, cheapest);
	// push
	refresh_index(*A, *B);
	prep_push(A, cheapest, 0);
	prep_push(B, cheapest->target, 1);
	push_b(A, B);
}

void	initiate_push_second(t_stack **A, t_stack **B)
{
	// print_both(*A, *B);
	refresh_index(*A, *B);
	prep_push(A, (*B)->target, 0);
	push_a(A, B);
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