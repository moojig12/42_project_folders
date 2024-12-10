/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:24:36 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/26 14:24:16 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_hook *par)
{
	int	i;

	i = 0;
	while (i <= 40)
	{
		mlx_destroy_image(par->game->mlx, par->sprites[i]->sprite);
		free(par->sprites[i]);
		i++;
	}
	free(par->sprites);
	mlx_destroy_window(par->game->mlx, par->game->win);
	mlx_destroy_display(par->game->mlx);
	free(par->game->mlx);
	free_buff(par);
	free_map(par);
	free(par->game->player_pos);
	free(par->game);
	free(par);
}

void	free_par(t_hook *par)
{
	int	i;

	i = 0;
	while (i <= 40)
	{
		free(par->sprites[i]);
		i++;
	}
	free(par->sprites);
	free(par->game->player_pos);
	free(par->game);
	free(par);
}

void	free_map(t_hook *par)
{
	int	i;

	i = 0;
	while (i < par->game->map.height)
	{
		free(par->game->map.layout[i]);
		i++;
	}
	free(par->game->map.layout);
}

void	free_buff(t_hook *par)
{
	int	i;

	i = 0;
	while (i < par->game->map.height)
	{
		free(par->game->map.buff[i]);
		i++;
	}
	free(par->game->map.buff);
}

void	free_gnl(char *line, int fd)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
