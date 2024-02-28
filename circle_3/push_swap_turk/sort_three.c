/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:43:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 20:12:53 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **A)
{
	t_stack	*max;

	if (list_size(*A) != 3)
		return ;
	max = get_high(*A);
	if (max == (*A))
		rotate_a(A);
	else if ((*A)->next == max)
		reverse_a(A);
	if ((*A) > (*A)->next && !check_sort(*A))
		swap_a(A);
}