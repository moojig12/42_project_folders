/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:01:15 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 17:14:12 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *input)
{
	int		i;
	int		positive;
	long	integer;

	i = 0;
	integer = 0;
	positive = 1;
	while ((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
		i++;
	if (input[i] == '-' || input[i] == '+')
	{
		if (input[i] == '-')
			positive = 0;
		i++;
	}
	while ((input[i] <= 57 && input[i] >= 48))
	{
		integer *= 10;
		integer += input[i] - '0';
		i++;
	}
	if (positive == 0)
		return (-integer);
	return (integer);
}
/* 
int	main()
{
	printf("%i", ft_atol("2023096690"));
} */