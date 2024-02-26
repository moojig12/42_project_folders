/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:11:05 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:04:16 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
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
		ft_printf("position %i: %i\n", i, temp->content);
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