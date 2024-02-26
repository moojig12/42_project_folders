/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 09:14:03 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_stack *A)
{
	t_stack	*temp;
	t_stack	*fast_temp;

	temp = A;
	fast_temp = A->next;
	while (temp->next != NULL)
	{
		fast_temp = temp->next;
		while (fast_temp->next != NULL)
		{
			if (fast_temp->content == temp->content)
			{
				// ft_printf("fast:%i | temp:%i\n", fast_temp->content, temp->content);
				error("List has doubles!");
			}
			fast_temp = fast_temp->next;
		}
		temp = temp->next;
	}
}

int	skip_delimiter(char *string, int i)
{
	while (string[i] < '0' || string[i] > '9')
	{
		ft_printf("hekpeawfawe");
		i++;
	}
	ft_printf("here: %c, %i\n", string[i], i);
	return (i);
}

void	append_node(t_stack **stack, long content)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->content = content;
	if (!stack || !*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = node;
		node->prev = last;
	}
	return ;
}