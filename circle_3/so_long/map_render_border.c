/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_border.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:48:06 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 14:48:07 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_upper_border(t_game *game, t_sprites **sprites, int y, int x)
{
	if (x == game->map.width - 1 || x == 0 || game->map.layout[1][x] == '1')
		filler_wall(game, sprites, x, y);
	else if (x < game->map.width - 1)
		type_sprite(game, sprites[11], x, y);
}

void	put_left_border(t_game *game, t_sprites **sprites, int y, int x)
{
	if (y == game->map.height - 1 || game->map.layout[y][x + 1] == '1')
		filler_wall(game, sprites, x, y);
	else if (y < game->map.height - 1)
		type_sprite(game, sprites[9], x, y);
}

void	put_right_border(t_game *game, t_sprites **sprites, int y, int x)
{
	if (!(game->map.layout[y][x - 1] == '1'))
		type_sprite(game, sprites[13], x, y);
	else
		filler_wall(game, sprites, x, y);
}

void	put_lower_border(t_game *game, t_sprites **sprites, int y, int x)
{
	if (x == game->map.width - 1 || x == 0 || game->map.layout[y - 1][x] == '1')
		filler_wall(game, sprites, x, y);
	else if (x < game->map.width - 1)
		type_sprite(game, sprites[7], x, y);
}

void	put_wall(t_game *game, t_sprites **sprites, int y, int x)
{
	if (y == 0)
		put_upper_border(game, sprites, y, x);
	else if (x == 0)
		put_left_border(game, sprites, y, x);
	else if (x == game->map.width - 1 && y < game->map.height - 1 && y != 0)
		put_right_border(game, sprites, y, x);
	else if (y == game->map.height - 1)
		put_lower_border(game, sprites, y, x);
	else
		put_other_walls(game, sprites, x, y);
	return ;
}
