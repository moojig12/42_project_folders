/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:49:16 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:32 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **A)
{
	swap(A);
	printf("sa\n");
}

void	swap_b(t_stack **B)
{
	swap(B);
	printf("sb\n");
}

void	swap_r(t_stack **A, t_stack **B)
{
	swap(A);
	swap(B);
	printf("ss\n");
}