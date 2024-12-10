/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:17:01 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 14:52:36 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_character(t_game *game, void *sprite)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, \
	game->player_pos[1] * TILE_SIZE, \
	game->player_pos[0] * TILE_SIZE);
}

void	render_character(t_game *game, t_sprites **sprites)
{
	if (!game->last_movement)
		game->last_movement = 0;
	if (game->last_movement == UP)
	{
		put_character(game, sprites[17]->sprite);
	}
	else if (game->last_movement == DOWN)
	{
		put_character(game, sprites[19]->sprite);
	}
	else if (game->last_movement == LEFT)
	{
		put_character(game, sprites[20]->sprite);
	}
	else if (game->last_movement == RIGHT)
	{
		put_character(game, sprites[18]->sprite);
	}
	else
	{
		put_character(game, sprites[19]->sprite);
	}
}
