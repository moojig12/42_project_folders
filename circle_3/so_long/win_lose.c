/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:34 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 14:48:38 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_hook *par, int *pos)
{
	ft_printf("Yay! You won!!!\n");
	free(pos);
	free_all(par);
	exit (0);
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
