/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:48:42 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 15:51:34 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_format(char *string)
{
	int	len;

	len = ft_strlen(string);
	if (ft_strncmp(string, "maps/", 5) != 0)
	{
		ft_printf("Wrong format.\n");
		exit (0);
	}
	else if (ft_strncmp(&string[len - 4], ".ber", 4))
	{
		ft_printf("Wrong format.\n");
		exit(0);
	}
}
