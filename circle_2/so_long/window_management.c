/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:14:45 by nmandakh          #+#    #+#             */
/*   Updated: 2024/02/21 17:53:22 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_hook *par)
{
	free(par->game->pos);
	free_all(par);
	exit (0);
}

void	init_screen(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width, \
	game->height, "Slime :)");
}

void	hooks(t_game *game, t_hook *hook_params)
{
	mlx_hook(game->win, 2, 1L << 0, movement, hook_params);
	mlx_hook(game->win, 17, 0, close_window, hook_params);
}
