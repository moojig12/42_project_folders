/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:12:08 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 17:47:59 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_stack **A, t_stack **B)
{
	t_stack	*temp_a;
	t_stack *temp_b;

	temp_a = *A;
	temp_b = *B;
	printf("Head element: A-%i, B-NULL->%p\n", temp_a->content, temp_b);
	return ;
}