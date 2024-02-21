/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:20:51 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:24:11 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack {
	int		value;
	int		group;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//	load input into stack A
void	load_list(char **argv, int mode, t_stack **A);

//	push operations
int		push(t_stack **A, t_stack **B);

//	swap operations
int		swap(t_stack **stack);

// rotate operations
int		rotate(t_stack **stack);

// reverse rotate operations
int		reverse(t_stack **stack);

#endif