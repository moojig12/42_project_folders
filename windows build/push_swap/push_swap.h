/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:32:32 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 19:27:21 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/Libft/libft.h"
// # include "srcs/ft_printf/ft_printf.h"
// # include <unistd.h>
# include <stdlib.h>

//single linked list
typedef struct s_stack {
	
	int				content;
	struct s_stack	*next;
	// struct s_stack	*prev;
}	t_stack;

void	print_list(t_stack *stack);
int		check_sort(t_stack *stack);
void	short_sort(t_stack **A, t_stack **B);
void	bubble_sort(t_stack **A, t_stack **B);
void	nanni_sort(t_stack **A, t_stack **B);
void	load_array(t_stack **A, char **argv);
void	load_list(t_stack **A, int argc, char **argv);
// swap operations
int		swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_swap(t_stack **stack_a, t_stack **stack_b);
// push operations
int		push(t_stack **dest, t_stack **origin);
void	push_a(t_stack **A, t_stack **B);
void	push_b(t_stack **A, t_stack **B);
// rotate operations
int		rotate(t_stack **stack);
void	rotate_a(t_stack **A);
void	rotate_b(t_stack **B);
void	rotate_rotate(t_stack **A, t_stack **B);
// reverse rotate operations
int		reverse(t_stack **stack);
void	reverse_a(t_stack **A);
void	reverse_b(t_stack **B);
void	reverse_reverse(t_stack **A, t_stack **B);

#endif

