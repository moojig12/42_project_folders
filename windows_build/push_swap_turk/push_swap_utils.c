#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
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
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = list_last(*stack);
	last->prev->next = NULL;
	last->next = NULL;
	*stack = last;
	last->next->prev = NULL;
}

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = list_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}