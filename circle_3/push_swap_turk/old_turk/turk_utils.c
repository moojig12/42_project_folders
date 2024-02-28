/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:13:37 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 16:43:11 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_stack **A)
{
	while ((*A)->content != get_low(*A)->content)
	{
		if (get_low(*A)->above_median)
			rotate_a(A);
		else
			reverse_a(A);
	}
}

void	current_index(t_stack *stack)
{
	t_stack	*temp;
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	temp = stack;
	median = list_size(temp) / 2;
	while (temp)
	{
		temp->index = i;
		if (i <= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		++i;
	}
}

void	prep_push(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		ft_printf("Node: %i, %i\n", (*stack)->content, node->content);
		print_list(node);
		print_list(*stack);
		if (stack_name == 'A')
		{
			if (node->above_median == 1)
				rotate_a(stack);
			else
				reverse_a(stack);
		}
		else if (stack_name == 'B')
		{
			if (node->above_median == 1)
				rotate_b(stack);
			else
				reverse_b(stack);
		}
	}
}