/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:39 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 17:15:33 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_array_character(char **argv, int i, int j)
{
	if (argv[i][0] == '"' && argv[i][ft_strlen(argv[i]) - 1] == '"')
	{
		i++;
		while (argv[i - 1])
		{
			while (argv[i][j])
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9') && \
				(argv[i][j] != '-' && argv[i][j] != '+'))
					error("Input includes a non-digit value");
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	check_character(char **argv, int mode)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (mode == 0)
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9') && \
				(argv[i][j] != '-' && argv[i][j] != '+'))
					error("Input includes a non-digit value");
				j++;
			}
			j = 0;
			i++;
		}
	}
	else if (mode == 1)
	{
		check_array_character(argv, i, j);
	}
}

int	argument_check(int argc, char **argv)
{
	if (argc < 2)
	{
		return (-1);
	}
	else if (argc == 2)
	{
		check_character(argv, 1);
		return (1);
	}
	else
	{
		check_character(argv, 0);
		return (0);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	load_list(argv, argument_check(argc, argv), &a);
	if (!a)
		return (0);
	if (check_sort(a) == 0)
	{
		if (list_size(a) == 2)
			swap_a(&a);
		else if (list_size(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
}
