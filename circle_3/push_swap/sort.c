/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:42:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 17:45:42 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **A, t_stack **B)
{
	t_stack	*temp_a;
	t_stack *temp_b;

	temp_a = *A;
	temp_b = *B;
	printf("%i, %i\n", temp_a->content, temp_b->content);
	return ;
}