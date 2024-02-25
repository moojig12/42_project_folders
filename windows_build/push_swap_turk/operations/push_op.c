#include "../push_swap.h"

void	push_a(t_stack **A, t_stack **B)
{
	push(A, B);
	ft_printf("pa\n");
}

void	push_b(t_stack **A, t_stack **B)
{
	push(B, A);
	ft_printf("pb\n");
}