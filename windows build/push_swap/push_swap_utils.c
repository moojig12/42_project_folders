/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:49:46 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 20:37:02 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;

	if (!stack)
	{	
		printf("Stack doesn't exist.\n");
		return (1);
	}
	else if (ft_lstsize((t_list *)*stack) == 1)
		return (1);
	else
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		return (0);
	}
}

int	push(t_stack **dest, t_stack **origin)
{
	t_stack *ptr;
	t_stack *new_head;

	if (!origin || !*origin)
		return (1);

	new_head = (*origin)->next;
	ptr = (t_stack *)ft_lstnew((*origin)->content);
	if (!ptr)
		return (1);
	ft_lstadd_front((t_list **)dest, (t_list *)ptr);
	if (new_head)
		*origin = new_head;
	else
		ft_lstclear((t_list **)origin, free);
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*ptr;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	head = (*stack)->next;
	ptr = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	ptr->next = NULL;
	last->next = ptr;
	*stack = head;
	return (0);
}

int	reverse(t_stack **stack)
{
	t_stack	*ptr;
	t_stack *ptr_prev;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	ptr = *stack;
	while (ptr->next != NULL)
	{
		ptr_prev = ptr;
		ptr = ptr->next;
	}
	ptr_prev->next = NULL;
	ptr->next = *stack;
	*stack = ptr;
	return (0);
}
int	reverse_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		i = stack->content;
		stack = stack->next;
		if (i < stack->content)
			return (0);
	}
	return (1);
}

int check_sort(t_stack *stack) {
	int i;

	while (stack != NULL && stack->next != NULL)
	{
		i = stack->content;
		stack = stack->next;
		if (i > stack->content)
			return 0;
	}
	return 1;
}