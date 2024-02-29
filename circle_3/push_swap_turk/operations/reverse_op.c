/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:54 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/29 12:57:32 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_a(t_stack **A)
{
	reverse(A);
	// print_list(*A);
	ft_printf("rra\n");
}

void	reverse_b(t_stack **B)
{
	reverse(B);
	ft_printf("rrb\n");
}

void	reverse_r(t_stack **A, t_stack **B)
{
	reverse(A);
	reverse(B);
	ft_printf("rrr\n");
}