#include "push_swap.h"

void	start_sort(t_stack **A, t_stack **B)
{
	printf("Current pointers: %p | %p\n", *A, *B);
	push_b(A, B);
	push_b(A, B);
	push_b(A, B);
	push_a(A, B);
	push_a(A, B);
	push_a(A, B);
	push_a(A, B);
	print_both(*A, *B);
	return ;
}