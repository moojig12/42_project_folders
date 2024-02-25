#include "../push_swap.h"

void	rotate_a(t_stack **A)
{
	rotate(A);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **B)
{
	rotate(B);
	ft_printf("rb\n");
}

void	rotate_r(t_stack **A, t_stack **B)
{
	rotate(A);
	rotate(B);
	ft_printf("rr\n");
}