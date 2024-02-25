/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:39 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 16:40:05 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **stack, t_stack **node)
{
	t_stack	*push_node;

	if (node == NULL)
		return ;
	push_node = *node;
	*node = (*node)->next;
	if (*node)
		(*node)->prev = NULL;
	push_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack;
		push_node->next->prev = push_node;
		*stack = push_node;
	}
}

void	reverse(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*onebeforetail;

	head = *stack;
	tail = list_last(*stack);
	onebeforetail = tail->prev;
	ft_lstadd_front_ps(stack, tail);
	(*stack)->next = head;
	onebeforetail->next = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*tail;

	head = *stack;
	second = (*stack)->next;
	tail = list_last(*stack);
	ft_lstadd_back_ps(&second, head);
	if (second && second->next)
	{
		second->prev = NULL;
		head->prev = tail;
		head->next = NULL;
		*stack = second;
	}
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	head = *lst;
	if (lst)
	{
		if (head)
		{
			new->next = head;
			head->prev = new;
		}
		new->prev = NULL;
		*lst = new;
	}
	new->next = lst[0];
	*lst = new;
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlast_ps(*lst);
	if (!last)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}



void	print_list(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	if (!stack)
	{
		printf("list empty\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		printf("position %i: %i\n", i, temp->content);
		i++;
		temp = temp->next;
	}
}

void	print_both(t_stack *A, t_stack *B)
{
	printf("Stack A\n");
	print_list(A);
	printf("Stack B\n");
	print_list(B);
}