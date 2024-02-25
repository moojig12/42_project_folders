/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:17:23 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/24 16:38:12 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_double(t_stack *A)
{
	t_stack	*temp;
	t_stack	*fast_temp;

	temp = A;
	fast_temp = A->next;
	while (temp->next != NULL)
	{
		fast_temp = temp->next;
		while (fast_temp->next != NULL)
		{
			if (fast_temp->content == temp->content)
			{
				// printf("fast:%i | temp:%i\n", fast_temp->content, temp->content);
				error("List has doubles!");
			}
			fast_temp = fast_temp->next;
		}
		temp = temp->next;
	}
}

static void	load_all(t_stack **A, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_back_ps(A, new_node(ft_atoi(argv[i])));
		i++;
	}
}

/* _stack	*pop_stack(t_stack *a_stack, int argc, char **argv)
{
	t_stack	*new;
	int		i;
	new = NULL;
	i = 1;
	if (argc <= 1)
		exit (1);
	else
	{
		while (argv[i])
		{
			// if (errors(argv[i]) == 1 || (ft_atoi_ps(argv[i]) > 2147483647)
			// 	|| (ft_atoi_ps(argv[i]) < -2147483648))
			// 	errorescape(a_stack);
			// if (error_dup(a_stack, ft_atoi_ps(argv[i])))
			// 	errorescape(a_stack);
			new = ft_lstnew_ps(ft_atoi(argv[i]));
			ft_lstadd_back_ps(&a_stack, new);
			i++;
		}
	}
	return (a_stack);
} */

static void	skip_delimiter(char *string, int *i)
{
	while (string[(*i)] < '0' || string[(*i)] > '9')
	{
		(*i)++;
	}
}

static void load_array(t_stack **A, char *string)
{
	int	num;
	int	i;

	i = 0;
	skip_delimiter(string, &i);
	while (string[i])
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			num = (ft_atoi(&string[i]));
			while (string[i] >= '0' && string[i] <= '9')
				i++;
		}
		else
		{
			insert_node(A, new_node(num));
			num = 0;
			skip_delimiter(string, &i);
		}
	}
	if (num != 0)
		insert_node(A, new_node(num));
	return ;
}

void	load_list(char **argv, int mode, t_stack **A)
{
	if (mode == 1)
		load_array(A, argv[1]);
	else if (mode == 0)
		load_all(A, argv);
	// check if there are doubles
	check_double(*A);
}
