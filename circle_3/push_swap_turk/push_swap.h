/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:35 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/26 13:09:04 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "lib/Libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

typedef struct s_stack {
	long			content;
	int				cost;
	int				index;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

/* typedef struct s_head
{
	struct s_stack *A;
	struct s_stack *B;
}	t_head;
 */

// utilities
void	error(char *s);
void	print_list(t_stack *stack);
void	print_both(t_stack *A, t_stack *B);
t_stack	*last_node(t_stack *stack);

// list utilities
int		list_size(t_stack *stack);
long		get_high(t_stack *stack);
int		check_sort_a(t_stack *stack);
int		check_sort_b(t_stack *stack);;
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

//	rotate operations
void	rotate(t_stack **stack);
void	rotate_a(t_stack **stack);
void	rotate_b(t_stack **stack);

//	reverse rotate operations
void	reverse(t_stack **stack);
void	reverse_a(t_stack **stack);
void	reverse_b(t_stack **stack);

//	misc sort
void	sort_three(t_stack **A);

//	turk sort
void	turk_sort(t_stack **A, t_stack **B);

#endif