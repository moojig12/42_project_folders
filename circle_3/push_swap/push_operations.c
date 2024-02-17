/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:12:13 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 14:14:49 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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