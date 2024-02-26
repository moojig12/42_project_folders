/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:33 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:12:45 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_b_push(t_stack **A, t_stack **B)
{
	while (list_size(*A) > 3)
	{
		find_target(*A, *B);
		calculate_cost(*A, *B);
		do_op(A, B);
	}
}

void	turk_sort(t_stack **A, t_stack **B)
{
	push_b(A, B);
	push_b(A, B);
	start_b_push(A, B);
	start_a_push(A, B);
}