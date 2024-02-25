/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:36 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 16:28:39 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_b(A, B)
// {
// 	// sort B
// }

int	cycle_a(t_stack **A)
{
	swap_a(A);
	rotate_a(A);
	return (1);
}

int	index_node(t_stack *stack)
{
	t_stack	*node;
	t_stack	*head;
	int		i;

	node = stack->next;
	head = stack;
	i = 0;
	// pre-exits
	if (list_size(stack) == 1)
		return (0);
	else if (list_size(stack) == 2)
	{
		if (check_sort(stack) == 0)
			return (1);
		else if (check_sort(stack) == 1)
			return (0);
	}
	else if (head->content < list_last(stack)->content)
		return (-1);
	// indexing
	while ((head->content < node->content) && node != NULL)
	{
		i++;
		if (node->next != NULL)
			node = node->next;
		else
			break ;
	}
	return (i);
}

int	cycle_b(t_stack **B)
{
	if (check_sort(*B) == 1)
		return (0);
	swap_b(B);
	if (check_sort(*B) == 1)
		return (0);
	rotate_b(B);
	if (check_sort(*B) == 1)
		return (0);
	return (1);
}

int	cycle_reverse_b(t_stack **B)
{
	reverse_b(B);
	swap_b(B);
	return (1);
}

void	sort_insertion_b(t_stack **B)
{
	t_stack	*temp;
	int		i;
	int		reverse;

	temp = *B;
	i = index_node(*B);
	// print_list(*B);
	reverse = 0;
	if (check_sort(*B) == 1)
		return ;
	else if (i < 0)
	{
		rotate_b(B);
		return ;
	}
	else if (i <= list_size(*B) / 2)
	{
		while (i > 0)
		{
			reverse += cycle_b(B);
			if (check_sort(*B) == 1)
			{
				i = 0;
				break ;
			}
			i--;
		}
	}
	else if ((i > list_size(*B) / 2) && i != 0)
	{
		reverse = -1;
		i = list_size(*B) - i - 1;
		while (i > 0)
		{
			reverse -= cycle_reverse_b(B);
			i--;
		}
		// print_list(*B);
	}
	while (reverse > 0)
	{
		reverse--;
		reverse_b(B);
	}
	while (reverse < 0)
	{
		reverse++;
		rotate_b(B);
	}
}

void	start_sort(t_stack **A, t_stack **B)
{
	int	i;
	int	size;

	i = 0;
	// start loading elements to pb all except biggest element ✓
	while (list_size(*A) > 1)
	{
		if ((*A)->content != get_high(*A))
		{
			push_b(A, B);
			sort_insertion_b(B);
		}
		else
		{
			rotate_a(A);
		}
		i++;
	}
	// print_both(*A, *B);
	size = list_size(*B);
	// printf("Size: %i\n", size);
	while (size > 0)
	{
		push_a(A, B);
		size--;
	}
	// printf("Moves: %i\n", i);
	//		..

	//		calculation and push?

	//		insertion algo
	// compare if prev is bigger and next is smaller
	// calculate if reverse or normal insertion is cheaper
	// if node is smaller than last element use rotate
	// if condition is met don't shift through elements anymore
	// shift = swap -> rotate | after condition is met reverse back

	return ;
}