/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:14:45 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/06 15:46:24 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	load_all(t_stack **A, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		append_node(A, ft_atol(argv[i]));
		i++;
	}
}

static void	load_array(t_stack **A, char *string)
{
	long	num;
	int		i;

	i = 0;
	i = skip_delimiter(string, i);
	while (string[i])
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			num = (ft_atol(&string[i]));
			while (string[i] != '\0' && (string[i] >= '0' && string[i] <= '9'))
				i++;
			append_node(A, num);
			num = 0;
		}
		else
			i = skip_delimiter(string, i);
	}
	if (num != 0)
		append_node(A, (long)num);
	return ;
}

void	load_list(char **argv, int mode, t_stack **A)
{
	if (mode == 1)
		load_array(A, argv[1]);
	else if (mode == 0)
		load_all(A, argv);
	else
		return ;
	check_double(*A);
}
