/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 17:14:37 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_stack *A)
{
	t_stack	*temp;
	t_stack	*fast_temp;

	temp = A;
	fast_temp = A->next;
	while (temp)
	{
		fast_temp = temp->next;
		while (fast_temp)
		{
			if (fast_temp->content == temp->content)
			{
				free_stack(&A);
				error("List has doubles!");
			}
			fast_temp = fast_temp->next;
		}
		if (temp->content > INT_MAX || temp->content < INT_MIN)
		{
			free_stack(&A);
			error("Meow");
		}
		temp = temp->next;
	}
}

int	skip_delimiter(char *string, int i)
{
	while ((string[i] < '0' || string[i] > '9') \
	&& (string[i] != '-' && string[i] != '+'))
		i++;
	return (i);
}

static t_stack	*allocate_node(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	new->above_median = INT_MAX;
	new->cheapest = INT_MAX;
	new->cost = INT_MAX;
	new->index = INT_MIN;
	new->target = NULL;
	return (new);
}

void	append_node(t_stack **stack, long content)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	new = allocate_node(content);
	if (!stack || !*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
	return ;
}
