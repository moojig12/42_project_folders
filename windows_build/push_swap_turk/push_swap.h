#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack {
	int	content;
	int	cost;
	int	index;
	bool	above_median;
	bool	cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

typedef struct s_head
{
	struct s_stack *node;
	struct s_stack *node;
}	t_head;

// populating stack A
void	check_double(t_stack *A);
void	skip_delimiter(char *string, int *i);
void	append_node(t_stack **stack, int content);
void	load_list(char **argv, int mode, t_stack **A);

#endif