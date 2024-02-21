/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:01:35 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 17:03:30 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// *i is for cardinal directions, i[0] West, i[1] North, i[2] East, i[3] South
// later on used for putting the correct wall type

void	check_wall_adjacency(t_game *game, int *adjacency, int x, int y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		adjacency[i] = 0;
		i++;
	}
	if (game->map.layout[y][x - 1] == '1')
		adjacency[0] = 1;
	if (game->map.layout[y - 1][x] == '1')
		adjacency[1] = 1;
	if (game->map.layout[y][x + 1] == '1')
		adjacency[2] = 1;
	if (game->map.layout[y + 1][x] == '1')
		adjacency[3] = 1;
}

void	filler_wall(t_game *game, t_sprites **sprites, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	sprites[4]->sprite, (x * TILE_SIZE), (y * TILE_SIZE));
}

void	type_sprite(t_game *game, t_sprites *sprites, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	sprites->sprite, (x * TILE_SIZE), (y * TILE_SIZE));
}

void	check_validity(t_game *game, int y, int x)
{
	if (game->map.layout[y][x] != '1')
	{
		if (game->map.layout[y][x] != '\n')
		{
			ft_printf("check:%c|x:%i|y:%i\n", game->map.layout[y][x], x, y);
			ft_printf("Incorrect map format!\n");
			exit (0);
		}
	}
}

void	render_map(t_game *game, t_sprites **sprites)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		while (j < game->map.width)
		{
			if (game->map.layout[i][j] == '1')
				put_wall(game, sprites, i, j);
			else if (game->map.layout[i][j] == 'C')
				put_coin(game, sprites, i, j);
			else if (game->map.layout[i][j] == 'X')
				put_enemy(game, sprites, i, j);
			else if (game->map.layout[i][j] == 'E')
				put_exit(game, sprites, i, j);
			else
				put_grass(game, sprites, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
