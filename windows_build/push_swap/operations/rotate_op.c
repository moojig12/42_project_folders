/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:49:14 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:32 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **A)
{
	rotate(A);
	printf("ra\n");
}

void	rotate_b(t_stack **B)
{
	rotate(B);
	printf("rb\n");
}

void	rotate_r(t_stack **A, t_stack **B)
{
	rotate(A);
	rotate(B);
	printf("rr\n");
}