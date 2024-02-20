/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 20:52:20 by nmandakh         ###   ########.fr       */
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

	temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;
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
			if (arr[j] > arr[j + 1]) {
				// Swap arr[j] and arr[j+1]
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

int	get_median(t_stack *A, int low, int high)
{
	t_stack	*ptr;
	int median;
	int	size;
	int	*array;
	int	i;

	i = 0;
	size = ft_lstsize(A);
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	ptr = A;
	while (ptr)
	{
		array[i++] = current->data;
		ptr = ptr->next;
	}
	sort_array(array, size);
	if (size % 2 == 0)
		median = (arr[(size / 2) - 1] + arr[size / 2]) / 2.0;
	else
		median = arr[size / 2];
	free(array);
	return (median);
}

void	sort(t_stack **A, t_stack **B)
{
	// t_stack	*temp_a;
	// t_stack *temp_b;
	int	size;
	int	low;
	int	high;
	int	i;
	int	median;

	i = 0;
	// temp_a = *A;
	// temp_b = *B;
	size = ft_lstsize((t_list *)temp_a);
	low = get_low(temp_a);
	high = get_high(temp_a);
	median = get_median(*A, low, high)
	printf("median: %i\n", median);
	while (i < size / 2)
	{
		if ((*A)->content < median)
			push_b(A, B);
		else
			rotate_a(A);
		i++;
	}
	ft_printf("*Stack A*\n");
	print_list(*A);
	ft_printf("*Stack B*\n");
	print_list(*B);
	return ;
}