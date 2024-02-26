/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:53 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 08:14:54 by nmandakh         ###   ########.fr       */
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