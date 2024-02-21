/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 15:49:53 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_high(t_stack *stack)
{
	int	high;

	high = stack->content;
	while (stack->next != NULL)
	{
		if (high < stack->next->content)
			high = stack->next->content;
		stack = stack->next;
	}
	return (high);
}

int		get_low(t_stack *stack)
{
	int	low;

	low = stack->content;
	while (stack->next != NULL)
	{
		if (low > stack->next->content)
			low = stack->next->content;
		stack = stack->next;
	}
	return (low);
}

void	int_swap(int *array, int j)
{
	int temp;

	temp = array[j];
	array[j] = array[j + 1];
	array[j + 1] = temp;
}

void	sort_array(int *array, int size)
{
	int swapped;
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1) {
			if (array[j] > array[j + 1]) {
				// Swap array[j] and array[j+1]
				int_swap(array, j);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break;
		i++;
	}
}

int	get_median(t_stack *A)
{
	t_stack	*ptr;
	int median;
	int	size;
	int	*array;
	int	i;

	i = 0;
	size = ft_lstsize((t_list *)A);
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	ptr = A;
	while (ptr)
	{
		array[i++] = ptr->content;
		ptr = ptr->next;
	}
	sort_array(array, size);
	if (size % 2 == 0)
		median = (array[(size / 2) - 1] + array[size / 2]) / 2.0;
	else
		median = array[size / 2];
	free(array);
	return (median);
}

void	print_both(t_stack *A, t_stack *B)
{
	ft_printf("*Stack A*\n");
	print_list(A);
	ft_printf("*Stack B*\n");
	print_list(B);
}

// int	find_next_num(int current, t_stack *B)
// {

// }

// int	sort_step(t_stack **A)
// {
// 	t_stack	*temp;
// 	int	current;

// 	temp = *A;
// 	current = (*A)->content;

// }

// int	reverse_sort_step(t_stack **B)
// {
// 	t_stack	*temp;
// 	int	operation;
// 	int	current;
// 	int	adj;

// 	temp = *B;
// 	while ()
// 	{
// 		current = (*B)->content;
// 		adj = find_next_num(current, *B);
// 	}
// 	return (operation);
// }

// void	big_sort(t_stack **A, t_stack **B)
// {
// 	int	median_a;
// 	int	median_b;

// 	median_a = get_median(A);
// 	median_b = get_median(B);
// 	while (!check_sort(*A) && !reverse_sorted(*B))
// 	{
// 		sort_step(A);
// 		reverse_sort_step(B);
// 	}
// }

void	bubble_sort(t_stack **A, t_stack **B)
{
	// t_stack	*temp_a;
	// t_stack *temp_b;
	int	size;
	int	low;
	// int	i;
	int	median;
	int	i;

	i = 0;
	// temp_a = *A;
	// temp_b = *B;
	size = ft_lstsize((t_list *)*A);
	median = get_median(*A);
	ft_printf("median: %i\nsize: %i\n", median, size);
	while (ft_lstsize((t_list *)*A) > 1)
	{
		low = get_low(*A);
		if ((*A)->content == low)
			push_b(A, B);
		else if (ft_lstlast((t_list *)*A)->content == low)
		{
			rotate_a(A);
			push_b(A, B);
		}
		else
			rotate_a(A);
		i++;
	}
	ft_printf("moves: %i\n", i);
	print_both(*A, *B);
	// big_sort(A, B);
	return ;
}

/* void	group_sides(t_stack **A, t_stack **B)
{
	return ;
} */

void	nanni_sort(t_stack **A, t_stack **B)
{
	t_stack	*ptr;
	int	median;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize((t_list *)*A);
	median = get_median(*A);
	ft_printf("size: %i\nmedian: %i\n", size, median);
	while (ft_lstsize((t_list *)*A) - 1 > size / 2)
	{
		ptr = *A;
		if (ptr->content < median)
		{
			push_b(A, B);
			// small_to_bottom(B);
			// print_both(*A, *B);
		}
		else
		{
			rotate_a(A);
		}
		i++;
	}
	ft_printf("pushed: %i\n", i);
	sort_sides(A, B);
	print_both(*A, *B);
}