/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:11:05 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 14:31:31 by nmandakh         ###   ########.fr       */
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
		ft_printf("index: %i | value: \033[0;36m%i\033[0m\n", temp->index, temp->content);
		
		ft_printf("cost: %i\n", temp->cost);
		
		ft_printf("\033[0;32mpointer address: %p\033[0m\n", temp);
		ft_printf("\033[0;35mtarget: %p\033[0m\n", temp->target);
		if (temp->target != NULL)
			ft_printf("\033[0;35mtarget value: %i\033[0m\n", temp->target->content);
		ft_printf("\n");
		i++;
		temp = temp->next;
	}
}

void	print_both(t_stack *A, t_stack *B)
{
	ft_printf("\033[0;31mStack A\033[0m\n");
	print_list(A);
	ft_printf("\033[0;34mStack B\033[0m\n");
	print_list(B);
}