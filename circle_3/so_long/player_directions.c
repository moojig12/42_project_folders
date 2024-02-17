/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:18:53 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:28:16 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_up(t_hook *par, int y, int x, int *pos)
{
	if (par->game->map.layout[y - 1][x] == 'E')
		win(par, pos);
	else if (par->game->map.layout[y - 1][x] == 'X')
		lose(par, pos);
	else if (par->game->map.layout[y - 1][x] == 'C')
		give_coin(par->game);
	put_grass(par->game, par->sprites, y, x);
	par->game->player_pos[0]--;
	par->game->last_movement = UP;
	par->game->movement++;
	render_character(par->game, par->sprites);
}

void	update_down(t_hook *par, int y, int x, int *pos)
{
	if (par->game->map.layout[y + 1][x] == 'E')
		win(par, pos);
	else if (par->game->map.layout[y + 1][x] == 'X')
		lose(par, pos);
	else if (par->game->map.layout[y + 1][x] == 'C')
		give_coin(par->game);
	put_grass(par->game, par->sprites, y, x);
	par->game->player_pos[0]++;
	par->game->last_movement = DOWN;
	par->game->movement++;
	render_character(par->game, par->sprites);
}

void	update_left(t_hook *par, int y, int x, int *pos)
{
	if (par->game->map.layout[y][x - 1] == 'E')
		win(par, pos);
	else if (par->game->map.layout[y][x - 1] == 'X')
		lose(par, pos);
	else if (par->game->map.layout[y][x - 1] == 'C')
		give_coin(par->game);
	put_grass(par->game, par->sprites, y, x);
	par->game->player_pos[1]--;
	par->game->last_movement = LEFT;
	par->game->movement++;
	render_character(par->game, par->sprites);
}

void	update_right(t_hook *par, int y, int x, int *pos)
{
	if (par->game->map.layout[y][x + 1] == 'E')
		win(par, pos);
	else if (par->game->map.layout[y][x + 1] == 'X')
		lose(par, pos);
	else if (par->game->map.layout[y][x + 1] == 'C')
		give_coin(par->game);
	put_grass(par->game, par->sprites, y, x);
	par->game->player_pos[1]++;
	par->game->last_movement = RIGHT;
	par->game->movement++;
	render_character(par->game, par->sprites);
}

void	update_pos(t_hook *par, int move, int y, int x)
{
	par->game->map.layout[y][x] = '0';
	if (move == UP && par->game->pos[1] != 1)
		update_up(par, y, x, par->game->pos);
	else if (move == DOWN && par->game->pos[3] != 1)
		update_down(par, y, x, par->game->pos);
	else if (move == LEFT && par->game->pos[0] != 1)
		update_left(par, y, x, par->game->pos);
	else if (move == RIGHT && par->game->pos[2] != 1)
		update_right(par, y, x, par->game->pos);
	else if (move == ESC)
	{
		free(par->game->pos);
		free_all(par);
		exit (0);
	}
}
