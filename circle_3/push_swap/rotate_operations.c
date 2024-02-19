/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:15:00 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 14:33:24 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_rotate(t_stack **A, t_stack **B)
{
	rotate(A);
	rotate(B);
	printf("rr\n");
}