#include "../push_swap.h"

void	reverse_a(t_stack **A)
{
	reverse(A);
	ft_printf("rra\n");
}

void	reverse_b(t_stack **B)
{
	reverse(B);
	ft_printf("rrb\n");
}

void	reverse_r(t_stack **A, t_stack **B)
{
	reverse(A);
	reverse(B);
	ft_printf("rrr\n");
}