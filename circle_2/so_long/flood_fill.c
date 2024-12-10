/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:04:23 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 15:40:38 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	inner_look(t_game *game, int *i, int *j, int *booly)
{
	while ((*j) < game->map.width - 1 && (*booly) == 0)
	{
		(*j)++;
		if (game->map.layout[(*i)][(*j)] == 'P')
			(*booly) = 1;
	}
}

static void	flood_look_for_player(t_game *game, int *pos, t_hook *par)
{
	int	i;
	int	j;
	int	booly;

	i = 0;
	j = 0;
	booly = 0;
	while (i < game->map.height - 1 && booly == 0)
	{
		if (game->map.layout[i][j] == 'P')
			break ;
		if (j < game->map.width - 1 && booly == 0)
			inner_look(game, &i, &j, &booly);
		if (booly == 1)
			break ;
		else if (booly != 1)
		{
			j = 0;
			i++;
		}
	}
	if (i == game->map.height || j == 0)
		flood_error(par, pos, "player not found!\n");
	pos[0] = i;
	pos[1] = j;
}

void	flood_wall_adjacency(char **buff, int *adjacency, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		adjacency[i] = 1;
		i++;
	}
	if (buff[y][x - 1] == '1' || buff[y][x - 1] == 1)
		adjacency[0] = 0;
	if (buff[y - 1][x] == '1' || buff[y - 1][x] == 1)
		adjacency[1] = 0;
	if (buff[y][x + 1] == '1' || buff[y][x + 1] == 1)
		adjacency[2] = 0;
	if (buff[y + 1][x] == '1' || buff[y + 1][x] == 1)
		adjacency[3] = 0;
}

void	recursive_flood(t_hook *par, int *i, int x, int y)
{
	if (par->game->map.buff[y][x] == 'C')
		(*i)++;
	else if (par->game->map.buff[y][x] == 'E')
		par->game->exit_found += 1;
	else if (par->game->map.buff[y][x] == 'P')
		par->game->players += 1;
	if (par->game->map.buff[y][x] == 1)
		return ;
	if ((par->game->map.buff[y][x] != '1' || \
	par->game->map.buff[y][x] != 'X'))
		par->game->map.buff[y][x] = 1;
	if (par->game->map.buff[y][x - 1] != '1' && par->game->\
	map.buff[y][x - 1] != 1 && par->game->map.buff[y][x - 1] != 'X')
		recursive_flood(par, i, x - 1, y);
	if (par->game->map.buff[y - 1][x] != '1' && par->game->\
	map.buff[y - 1][x] != 1 && par->game->map.buff[y - 1][x] != 'X')
		recursive_flood(par, i, x, y - 1);
	if (par->game->map.buff[y][x + 1] != '1' && par->game->\
	map.buff[y][x + 1] != 1 && par->game->map.buff[y][x + 1] != 'X')
		recursive_flood(par, i, x + 1, y);
	if (par->game->map.buff[y + 1][x] != '1' && par->game->\
	map.buff[y + 1][x] != 1 && par->game->map.buff[y + 1][x] != 'X')
		recursive_flood(par, i, x, y + 1);
}

void	flood_fill(t_hook *par)
{
	int		i;
	int		*pos;

	i = 0;
	pos = calloc(2, sizeof(int));
	par->game->exit_found = 0;
	par->game->players = 0;
	par->game->map.buff = duplicate_map(par);
	flood_look_for_player(par->game, pos, par);
	count_coins(par, pos);
	recursive_flood(par, &i, pos[1], pos[0]);
	if (par->game->exit_found == 0 || i != par->game->total_coins)
		flood_error(par, pos, \
		"Path to exit not found or a collectible is inaccessible!\n");
	else if (par->game->exit_found > 1)
		flood_error(par, pos, "More than one exit!\n");
	else if (par->game->players != 1)
		flood_error(par, pos, "Player count incorrect!\n");
	free(pos);
}
