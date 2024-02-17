/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:32:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:07 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/Libft/libft.h"
# include "srcs/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

//single linked list
typedef struct s_stack {
	
	int				content;
	struct s_stack	*next;
	// struct s_stack	*prev;
}	t_stack;

void	load_list(t_stack **A, int argc, char **argv);
int		swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
int		push(t_stack **dest, t_stack **origin);

#endif

