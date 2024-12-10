/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:35 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 16:16:08 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "lib/Libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_stack {
	long			content;
	int				cost;
	int				index;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

// utilities
void	error(char *s);
void	print_list(t_stack *stack);
void	print_both(t_stack *A, t_stack *B);
t_stack	*last_node(t_stack *stack);
void	free_stack(t_stack **stack);

// list utilities
t_stack	*ps_lstnew(int content);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
int		list_size(t_stack *stack);
int		check_sort(t_stack *stack);
// bool		check_sort_b(t_stack *stack);
t_stack	*get_high(t_stack *stack);
t_stack	*get_low(t_stack *stack);
t_stack	*last_node(t_stack *stack);

// populating stack A
void	check_double(t_stack *A);
int		skip_delimiter(char *string, int i);
void	append_node(t_stack **stack, long content);
void	load_list(char **argv, int mode, t_stack **A);

//	push operations
void	push(t_stack **dest, t_stack **node);
void	push_a(t_stack **A, t_stack **B);
void	push_b(t_stack **A, t_stack **B);

//	swap operations
void	swap(t_stack **stack);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	swap_s(t_stack **A, t_stack **B);

//	rotate operations
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);
void	rotate_r(t_stack **A, t_stack **B);

//	reverse rotate operations
void	reverse(t_stack **stack);
void	reverse_a(t_stack **stack);
void	reverse_b(t_stack **stack);
void	reverse_r(t_stack **A, t_stack **B);

//	misc sort
void	sort_three(t_stack **A);

//	turk utils
void	refresh_index(t_stack *A, t_stack *B);
t_stack	*get_cheapest(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	index_stack(t_stack *stack);
void	prep_push(t_stack **stack, t_stack *cheapest, int mode);

//	turk sort
void	turk_sort(t_stack **A, t_stack **B);
void	initiate_push_first(t_stack **A, t_stack **B);
void	initiate_push_second(t_stack **A, t_stack **B);
void	find_target_a(t_stack *A, t_stack *B);
void	find_target_b(t_stack *A, t_stack *B);
void	calculate_costs(t_stack *A, t_stack *B);
void	calculate_costs_b(t_stack *A, t_stack *B);
void	sort_min(t_stack **A);
void	rotate_both(t_stack **A, t_stack **B, t_stack *cheapest);
void	reverse_both(t_stack **A, t_stack **B, t_stack *cheapest);
// void	move_b_to_a(t_stack **A, t_stack **B);
// void	move_a_to_b(t_stack **A, t_stack **B);

#endif