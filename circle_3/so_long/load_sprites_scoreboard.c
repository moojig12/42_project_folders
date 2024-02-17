/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_scoreboard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:48:11 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:30:54 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_scoreboard1(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[23], "./textures/board/0.xpm");
	check_sprite(sprites[23]->sprite, i);
	load(game, sprites[24], "./textures/board/1.xpm");
	check_sprite(sprites[24]->sprite, i);
	load(game, sprites[25], "./textures/board/2.xpm");
	check_sprite(sprites[25]->sprite, i);
	load(game, sprites[26], "./textures/board/3.xpm");
	check_sprite(sprites[26]->sprite, i);
	load(game, sprites[27], "./textures/board/4.xpm");
	check_sprite(sprites[27]->sprite, i);
	load(game, sprites[28], "./textures/board/5.xpm");
	check_sprite(sprites[28]->sprite, i);
	load(game, sprites[29], "./textures/board/6.xpm");
	check_sprite(sprites[29]->sprite, i);
	load(game, sprites[30], "./textures/board/7.xpm");
	check_sprite(sprites[30]->sprite, i);
}

static void	load_scoreboard2(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[31], "./textures/board/8.xpm");
	check_sprite(sprites[31]->sprite, i);
	load(game, sprites[32], "./textures/board/9.xpm");
	check_sprite(sprites[32]->sprite, i);
	load(game, sprites[33], "./textures/board/board.xpm");
	check_sprite(sprites[33]->sprite, i);
	load(game, sprites[34], "./textures/board/S.xpm");
	check_sprite(sprites[34]->sprite, i);
	load(game, sprites[35], "./textures/board/C.xpm");
	check_sprite(sprites[35]->sprite, i);
	load(game, sprites[36], "./textures/board/R.xpm");
	check_sprite(sprites[36]->sprite, i);
	load(game, sprites[37], "./textures/board/M.xpm");
	check_sprite(sprites[37]->sprite, i);
	load(game, sprites[38], "./textures/board/V.xpm");
	check_sprite(sprites[38]->sprite, i);
	load(game, sprites[39], "./textures/board/colon.xpm");
	check_sprite(sprites[39]->sprite, i);
}

void	load_scoreboard(t_game *game, t_sprites **sprites, int *i)
{
	load_scoreboard1(game, sprites, i);
	load_scoreboard2(game, sprites, i);
}
