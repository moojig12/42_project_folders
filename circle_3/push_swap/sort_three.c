/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:43:47 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 18:48:34 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **A)
{
	t_stack	*max;

	if (list_size(*A) != 3)
		return ;
	max = get_high(*A);
	if (max->content == (*A)->content)
		rotate_a(A);
	else if ((*A)->next->content == max->content)
		reverse_a(A);
	if ((*A)->content > (*A)->next->content && !check_sort(*A))
		swap_a(A);
}
