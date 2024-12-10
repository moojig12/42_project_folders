/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:48:03 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:54 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_grass(t_game *game, t_sprites **sprites, int y, int x)
{
	type_sprite(game, sprites[5], x, y);
}

void	put_exit(t_game *game, t_sprites **sprites, int y, int x)
{
	type_sprite(game, sprites[21], x, y);
}

void	put_coin(t_game *game, t_sprites **sprites, int y, int x)
{
	type_sprite(game, sprites[22], x, y);
}

void	put_enemy(t_game *game, t_sprites **sprites, int y, int x)
{
	type_sprite(game, sprites[40], x, y);
}
