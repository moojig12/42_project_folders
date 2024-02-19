/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 20:52:20 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_high(t_stack *stack)
{
	int	high;

	high = stack->content;
	while (stack->next != NULL)
	{
		if (high < stack->next->content)
			high = stack->next->content;
		stack = stack->next;
	}
	return (high);
}

int		get_low(t_stack *stack)
{
	int	low;

	low = stack->content;
	while (stack->next != NULL)
	{
		if (low > stack->next->content)
			low = stack->next->content;
		stack = stack->next;
	}
	return (low);
}

void	sort(t_stack **A, t_stack **B)
{
	t_stack	*temp_a;
	t_stack *temp_b;
	int	size;
	int	low;
	int	high;
	int	i;

	i = 0;
	temp_a = *A;
	temp_b = *B;
	ft_printf("*Stack A*\n");
	print_list(*A);
	ft_printf("*Stack B*\n");
	print_list(*B);
	size = ft_lstsize((t_list *)temp_a);
	low = get_low(temp_a);
	high = get_high(temp_a);
	while (ft_lstsize((t_list *)*A) > size / 2)
	{
		if ((*A)->content < (high - low))
			push_b(A, B);
		else
			rotate_a(A);
	}
	ft_printf("*Stack A*\n");
	print_list(*A);
	ft_printf("*Stack B*\n");
	print_list(*B);
	return ;
}