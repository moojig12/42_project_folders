/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:17:33 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:24:48 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	inner_look(t_game *game, int *i, int *j, int *booly)
{
	while ((*j) < game->map.width - 1 && (*booly) == 0)
	{
		(*j)++;
		if (game->map.layout[(*i)][(*j)] == 'P')
			(*booly) = 1;
	}
}

void	look_for_player(t_game *game)
{
	int	i;
	int	j;
	int	booly;

	i = 0;
	j = 0;
	booly = 0;
	game->player_pos = calloc(2, sizeof(int));
	while (i < game->map.height - 1 && booly == 0)
	{
		if (game->map.layout[i][j] == 'P')
			break ;
		if (j < game->map.width - 1 && booly == 0)
			inner_look(game, &i, &j, &booly);
		if (booly == 1)
			break ;
		else if (booly != 1)
		{
			j = 0;
			i++;
		}
	}
	game->player_pos[0] = i;
	game->player_pos[1] = j;
}
