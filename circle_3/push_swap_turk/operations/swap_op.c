/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:57 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/28 17:30:36 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **A)
{
	swap(A);
	ft_printf("sa\n");
}

void	swap_b(t_stack **B)
{
	swap(B);
	ft_printf("sb\n");
}

void	swap_s(t_stack **A, t_stack **B)
{
	swap(A);
	swap(B);
	ft_printf("ss\n");
}