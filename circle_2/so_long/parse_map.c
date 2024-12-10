/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:23:38 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 16:49:25 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, int fd)
{
	int	i;

	i = 0;
	game->map.layout = (char **)malloc(game->map.height * sizeof(char *));
	while (i < game->map.height)
	{
		game->map.layout[i] = get_next_line(fd);
		if ((sl_strchr(game->map.layout[i], '\n') > 0))
		{
			game->map.layout[i][sl_strchr(game->map.layout[i], '\n')] = 0;
		}
		i++;
	}
	return ;
}

int	parse_map(t_game *game, char *file_name, t_hook *par)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_par(par);
		ft_printf("Map could not be opened");
		close(fd);
		exit (0);
	}
	check_map_size(game, fd, par);
	close(fd);
	open_file(&fd, file_name);
	load_map(game, fd);
	close(fd);
	check_map_validity(game, par);
	flood_fill(par);
	return (0);
}
