/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:43:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:08:43 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **A)
{
	t_stack	*max;

	max = get_high(*A);
	if (max == *A)
		ra(A);
	else if ((*A)->next == biggest_node)
		rra(A);
	if ((*A)->content > (*A)->next->content)
		swap_a(*A);
}