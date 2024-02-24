/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:49:10 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/23 16:01:27 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack **A, t_stack **B)
{
	push(A, B);
	ft_printf("pa\n");
}

void	push_b(t_stack **A, t_stack **B)
{
	push(B, A);
	ft_printf("pb\n");
}
