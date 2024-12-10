/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:48:13 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:30:51 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_slime(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[17], "./textures/slime/up_slime.xpm");
	check_sprite(sprites[17]->sprite, i);
	load(game, sprites[18], "./textures/slime/right_slime.xpm");
	check_sprite(sprites[18]->sprite, i);
	load(game, sprites[19], "./textures/slime/down_slime.xpm");
	check_sprite(sprites[19]->sprite, i);
	load(game, sprites[20], "./textures/slime/left_slime.xpm");
	check_sprite(sprites[20]->sprite, i);
	load(game, sprites[40], "./textures/slime/enemy_slime.xpm");
	check_sprite(sprites[40]->sprite, i);
	return ;
}

void	load_extra(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[21], "./textures/exit.xpm");
	check_sprite(sprites[21]->sprite, i);
	load(game, sprites[22], "./textures/pearl.xpm");
	check_sprite(sprites[22]->sprite, i);
}
