/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:27:45 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/26 13:17:39 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_x(t_hook *par)
{
	return (par->game->player_pos[1]);
}

int	player_y(t_hook *par)
{
	return (par->game->player_pos[0]);
}

int	movement(int keycode, t_hook *par)
{
	par->game->pos = calloc(4, sizeof(int));
	check_wall_adjacency(par->game, par->game->pos, \
		(player_x(par)), player_y(par));
	update_pos(par, keycode, player_y(par), \
		player_x(par));
	put_scoreboard(par->game, par->sprites);
	free(par->game->pos);
	return (0);
}

// wtf is this?
void	player(t_game *game, t_sprites **sprites)
{
	if (!game->player_pos)
		look_for_player(game);
	render_character(game, sprites);
	put_scoreboard(game, sprites);
}
