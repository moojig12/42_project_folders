/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:16:26 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/19 20:30:19 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_array(t_stack **A, char **argv)
{
	printf("%s", argv[0]);
	printf("%p\n", A);
	return ;
}

void	prelim(char *s)
{
	printf("prelim:%s\n", s);
}

void	load_list(t_stack **A, int argc, char **argv)
{
	t_stack	*new;
	int		i;

	i = 1;
	new = NULL;
	while (argv[i] && i < argc)
	{
		// prelim(argv[i]);
		if (!A)
		{
			new = (t_stack *)ft_lstnew(ft_atoi(argv[i]));
			A = &new;
		}
		else
		{
			// new = ft_lstnew(ft_atoi(argv[i]));
			ft_lstadd_front((t_list **)A, (t_list *)ft_lstnew(ft_atoi(argv[i])));
		}
		i++;
	}
}