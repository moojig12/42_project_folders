/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:11:05 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 20:26:27 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	print_list(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (!stack)
	{
		ft_printf("list empty\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		ft_printf("position: %i\n%i\n", i, temp->content);
		ft_printf("cost: %i\n", temp->cost);
		ft_printf("target: %i\n", stack->target->content);
		ft_printf("\n");
		i++;
		temp = temp->next;
	}
}

void	print_both(t_stack *A, t_stack *B)
{
	ft_printf("Stack A\n");
	print_list(A);
	ft_printf("Stack B\n");
	print_list(B);
}