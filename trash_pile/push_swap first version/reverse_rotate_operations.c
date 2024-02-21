/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:33:29 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 15:29:37 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_stack **A)
{
	reverse(A);
	ft_printf("rra\n");
}

void	reverse_b(t_stack **B)
{
	reverse(B);
	ft_printf("rrb\n");
}

void	reverse_reverse(t_stack **A, t_stack **B)
{
	reverse(A);
	reverse(B);
	ft_printf("rrr\n");
}