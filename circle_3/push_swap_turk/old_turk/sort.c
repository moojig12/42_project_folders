/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:33 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 14:06:45 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	turk_sort(t_stack **A, t_stack **B)
{
	int	size_a;

	size_a = list_size(*A);
	if (size_a-- > 3 && !check_sort(*A))
		push_b(A, B);
	if (size_a-- > 3 && !check_sort(*A))
		push_b(A, B);
	while (size_a-- > 3 && !check_sort(*A))
	{
		init_a_to_b(*A, *B);
		move_a_to_b(A, B);
	}
	if (!check_sort(*A))
		sort_three(A);
	while (*B)
	{
		init_a_to_b(*A, *B);
		move_b_to_a(A, B);
	}
	current_index(*A);
	last_sort(A);
}