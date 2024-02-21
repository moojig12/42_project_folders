/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:34 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 15:49:26 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_hook *par, int *pos)
{
	if (par->game->player_coins == par->game->total_coins)
	{
		ft_printf("Yay! You won!!!\n");
		free(pos);
		free_all(par);
		exit (0);
	}
	else
		return ;
}

void	lose(t_hook *par, int *pos)
{
	ft_printf("You lost! :(\n");
	free(pos);
	free_all(par);
	exit (0);
}

void	give_coin(t_game *game)
{
	game->player_coins += 1;
}

void	check_for_invalid_char(char c, t_hook *par, int *pos)
{
	if (c != 'C' && c != 'P' && c != 'E' && \
	c != 'X' && c != '0' && c != '1')
	{
		flood_error(par, pos, \
		"Invalid character present!\n");
		exit (0);
	}
}
