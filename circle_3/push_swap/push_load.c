/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:16:26 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/17 17:45:59 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_list(t_stack **A, int argc, char **argv)
{
	t_stack	*new;
	int		buff;
	int		i;

	i = 0;
	new = NULL;
	while (argv[i])
	{
		if (!A)
		{
			new = ft_lstnew(ft_atoi(argv[i]));
			A = &new;
			i++;
		}
		else
		{
			new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_back(A, new);
			i++;
		}
	}
}