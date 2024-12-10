/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_screen_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:19:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 14:52:43 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	measure_game_screen(t_game *game)
{
	game->height = TILE_SIZE * game->map.height;
	game->width = TILE_SIZE * game->map.width;
}
