/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:20:51 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 16:40:13 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/Libft/libft.h"
# include "srcs/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack {
	int		content;
	// int		sorted;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// utilities
void	error(char *s);
void	print_list(t_stack *stack);
void	print_both(t_stack *A, t_stack *B);
t_stack	*ft_lstlast_ps(t_stack *lst);

//	list functions
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void	insert_node(t_stack **stack, t_stack *node);
t_stack	*new_node(int content);
int		list_size(t_stack *stack);
int		get_high(t_stack *stack);
int		check_sort(t_stack *stack);
t_stack	*list_last(t_stack *stack);

//	load input into stack A
void	load_list(char **argv, int mode, t_stack **A);

//	push operations
void		push(t_stack **dest, t_stack **node);
void	push_a(t_stack **A, t_stack **B);
void	push_b(t_stack **A, t_stack **B);

//	swap operations
void		swap(t_stack **stack);
void		swap_a(t_stack **stack);
void		swap_b(t_stack **stack);

// rotate operations
void		rotate(t_stack **stack);
void		rotate_a(t_stack **stack);
void		rotate_b(t_stack **stack);

// reverse rotate operations
void		reverse(t_stack **stack);
void		reverse_a(t_stack **stack);
void		reverse_b(t_stack **stack);

// sort
void	start_sort(t_stack **A, t_stack **B);

#endif