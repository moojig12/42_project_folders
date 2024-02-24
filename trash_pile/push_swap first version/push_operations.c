/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:12:13 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 17:05:33 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **A, t_stack **B)
{
	// ft_printf("pushed %i to A\n", (*B)->content);
	push(A, B);
	ft_printf("pa\n");
}

void	push_b(t_stack **A, t_stack **B)
{
	// ft_printf("pushed %i to B\n", (*A)->content);
	push(B, A);
	ft_printf("pb\n");
}