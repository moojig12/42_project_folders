/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:49:46 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 14:40:49 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;

	if (!stack)
	{	
		ft_printf("Stack doesn't exist.\n");
		return (1);
	}
	else if (ft_lstsize(*stack) == 1)
		return (1);
	else
	{
		first = *stack;
		second = *stack;
		second = second->next;
		first->next = second->next;
		second->next = first;
		return (0);
	}
}

int	push(t_stack **dest, t_stack **origin)
{
	t_stack	*ptr;

	if (!origin)
		return (1);
	else if (!dest)
	{
		ptr = *origin;
		ptr->next = NULL;
		dest = ft_lstnew(ptr->content);
	}
	else
	{
		ptr = *origin;
		ptr->next = *dest;
		return (0);
	}
}

int	rotate(t_stack **stack)
{
	t_stack	*ptr;
	t_stack *ptr_prev;

	ptr = *stack;
	if (!stack)
	{
		ft_printf("Stack doesn't exist.\n");
		return (1);
	}
	while (ptr->next != NULL)
	{
		ptr_prev = ptr;
		ptr = ptr->next;
	}
	if (!ptr_prev)
	{
		ft_printf("Stack only has 1 node.\n");
		return (1);
	}
	else if (ptr_prev)
	{
		ptr_prev->next = NULL;
		ptr->next = *stack;
	}
	else
		return (1);
}

int	reverse(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*last_prev;

	head = *stack;
	last_prev = NULL;
	while (last->next != NULL)
	{
		last_prev = last;
		last = last->next;
	}
	if (!last_prev)
	{
		ft_printf("Stack only has 1 node.\n");
		return (1);
	}
	else if (last_prev)
	{
		last_prev->next = NULL;
		last->next = head;
	}
}