/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:46 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:02:21 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_score(t_game *game, void *sprite, int x, int y)
{
	if (x != 0 && y != 0)
		mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
}

static void	put_score_upper(t_game *game, t_sprites **sprites)
{
	int		x;
	int		y;
	int		i;
	char	*coins;

	x = 56;
	y = 10;
	i = 0;
	coins = ft_itoa(game->player_coins);
	if (game->player_coins < 10)
		put_image_score(game, sprites[23 + game->player_coins]->sprite, x, y);
	else
	{
		while (i < ft_strlen(coins))
		{
			put_image_score(game, \
			sprites[23 + coins[i] - '0']->sprite, x + (i * 10), y);
			i++;
		}
	}
	free(coins);
}

static void	put_score_down(t_game *game, t_sprites **sprites)
{
	int		x;
	int		y;
	int		i;
	char	*moves;

	x = 56;
	y = 26;
	i = 0;
	moves = ft_itoa(game->movement);
	if (game->movement < 10)
	{
		put_image_score(game, sprites[23 + game->movement]->sprite, x, y);
	}
	else
	{
		while (i < ft_strlen(moves))
		{
			put_image_score(game, \
			sprites[23 + moves[i] - '0']->sprite, x + (i * 10), y);
			i++;
		}
	}
	free(moves);
}

void	put_scoreboard(t_game *game, t_sprites **sprites)
{
	put_image_score(game, sprites[33]->sprite, 0, 0);
	put_image_score(game, sprites[34]->sprite, 6 * 2, 5 * 2);
	put_image_score(game, sprites[35]->sprite, 12 * 2, 5 * 2);
	put_image_score(game, sprites[36]->sprite, 18 * 2, 5 * 2);
	put_image_score(game, sprites[37]->sprite, 6 * 2, 13 * 2);
	put_image_score(game, sprites[38]->sprite, 12 * 2, 13 * 2);
	put_image_score(game, sprites[36]->sprite, 18 * 2, 13 * 2);
	put_image_score(game, sprites[39]->sprite, 24 * 2, 6 * 2);
	put_image_score(game, sprites[39]->sprite, 24 * 2, 14 * 2);
	put_score_down(game, sprites);
	put_score_upper(game, sprites);
}
