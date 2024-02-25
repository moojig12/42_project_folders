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

void	skip_delimiter(char *string, int *i)
{
	while (string[(*i)] < '0' || string[(*i)] > '9')
	{
		(*i)++;
	}
}

void	append_node(t_stack **stack, int content)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	
	if (!stack || !*stack)
		*stack = node;
	else
	{
		(*stack)->prev = node;
		node->next = (*stack);
		*stack = node;
	}
	return ;
}