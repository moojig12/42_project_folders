#include "../push_swap.h"

void	swap_a(t_stack **A)
{
	swap(A);
	ft_printf("sa\n");
}

void	swap_b(t_stack **B)
{
	swap(B);
	ft_printf("sb\n");
}

void	swap_r(t_stack **A, t_stack **B)
{
	swap(A);
	swap(B);
	ft_printf("ss\n");
}