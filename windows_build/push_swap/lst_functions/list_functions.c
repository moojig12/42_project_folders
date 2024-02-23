#include "../push_swap.h"

t_stack	*new_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	insert_node(t_stack **stack, t_stack *node)
{
	if (!node)
		error("Null node attempted to insert");
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
