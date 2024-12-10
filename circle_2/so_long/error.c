/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:01:31 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:11 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_error(t_hook *par, int *pos, char *error)
{
	ft_printf(error);
	free_buff(par);
	free_map(par);
	free_par(par);
	free(pos);
	exit (0);
}

void	map_error(char *error, int x, int y, t_hook *par)
{
	ft_printf("%s\nAt: x-%i y-%i", error, x, y);
	free_map(par);
	free_par(par);
	exit (1);
}

void	border_error(t_game *g, int y, int x, t_hook *par)
{
	if (y == 0)
	{
		if ((x < g->map.width || x == 0) && g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (x == 0)
	{
		if ((y == g->map.height - 1 || y < g->map.height - 1) \
		&& g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (x == g->map.width - 1 && y < g->map.height - 1 && y != 0)
	{
		if (g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (y == g->map.height - 1)
	{
		if ((x < g->map.width || x == 0) && g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else
		return ;
}
