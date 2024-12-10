/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:48:01 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:55:18 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	single_walls(t_game *game, t_sprites **sprites, int x, int y)
{
	if (game->cd[0] == 0 && game->cd[1] == 0 \
	&& game->cd[2] == 0 && game->cd[3] == 1)
		type_sprite(game, sprites[0], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 0 \
	&& game->cd[2] == 0 && game->cd[3] == 0)
		type_sprite(game, sprites[1], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 1 \
	&& game->cd[2] == 0 && game->cd[3] == 0)
		type_sprite(game, sprites[2], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 0 \
	&& game->cd[2] == 1 && game->cd[3] == 0)
		type_sprite(game, sprites[3], x, y);
}

static void	corner_walls(t_game *game, t_sprites **sprites, int x, int y)
{
	if (game->cd[0] == 1 && game->cd[1] == 1 \
	&& game->cd[2] == 1 && game->cd[3] == 1)
		filler_wall(game, sprites, x, y);
	if (game->cd[0] == 1 && game->cd[1] == 0 \
	&& game->cd[2] == 1 && game->cd[3] == 1)
		type_sprite(game, sprites[7], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 1 \
	&& game->cd[2] == 0 && game->cd[3] == 1)
		type_sprite(game, sprites[9], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 1 \
	&& game->cd[2] == 1 && game->cd[3] == 0)
		type_sprite(game, sprites[11], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 1 \
	&& game->cd[2] == 1 && game->cd[3] == 1)
		type_sprite(game, sprites[13], x, y);
}

static void	side_walls(t_game *game, t_sprites **sprites, int x, int y)
{
	if (game->cd[0] == 0 && game->cd[1] == 0 \
	&& game->cd[2] == 1 && game->cd[3] == 1)
		type_sprite(game, sprites[6], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 0 \
	&& game->cd[2] == 0 && game->cd[3] == 1)
		type_sprite(game, sprites[8], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 1 \
	&& game->cd[2] == 0 && game->cd[3] == 0)
		type_sprite(game, sprites[10], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 1 \
	&& game->cd[2] == 1 && game->cd[3] == 0)
		type_sprite(game, sprites[12], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 0 \
	&& game->cd[2] == 0 && game->cd[3] == 0)
		type_sprite(game, sprites[14], x, y);
	if (game->cd[0] == 0 && game->cd[1] == 1 \
	&& game->cd[2] == 0 && game->cd[3] == 1)
		type_sprite(game, sprites[15], x, y);
	if (game->cd[0] == 1 && game->cd[1] == 0 \
	&& game->cd[2] == 1 && game->cd[3] == 0)
		type_sprite(game, sprites[16], x, y);
}

void	put_other_walls(t_game *game, t_sprites **sprites, int x, int y)
{
	game->cd = calloc(4, sizeof(int));
	check_wall_adjacency(game, game->cd, x, y);
	single_walls(game, sprites, x, y);
	corner_walls(game, sprites, x, y);
	side_walls(game, sprites, x, y);
	free(game->cd);
}
