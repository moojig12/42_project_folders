/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:23:38 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:57:37 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *error, int x, int y, t_hook *par)
{
	ft_printf("%s\nAt: x-%i y-%i", error, x, y);
	free_par(par);
	exit (0);
}

void	border_error(t_game *g, int y, int x, t_hook *par)
{
	if (y == 0)
	{
		if ((x < g->map.width || x == 0) && g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (x == 0)
	{
		if ((y == g->map.height - 1 || y < g->map.height - 1) \
		&& g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (x == g->map.width - 1 && y < g->map.height - 1 && y != 0)
	{
		if (g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else if (y == g->map.height - 1)
	{
		if ((x < g->map.width || x == 0) && g->map.layout[y][x] != '1')
			map_error("Not surrounded by walls!", x + 1, y + 1, par);
	}
	else
		return ;
}

static void	check_map_size(t_game *game, int fd, t_hook *par)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (sl_strchr(line, '\n'))
		line[sl_strchr(line, '\n')] = 0;
	game->map.width = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
		if (line != NULL)
			if (sl_strchr(line, '\n'))
				line[sl_strchr(line, '\n')] = 0;
		if (!line)
			break ;
		if (((ft_strlen(line)) != game->map.width))
		{
			free_gnl(line, fd);
			map_error("Map width not consistent.", 0, 0, par);
		}
		game->map.width = ft_strlen(line);
	}
	game->map.height = i;
	if (line)
		free(line);
}

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

	open_file(&fd, file_name);
	check_map_size(game, fd, par);
	close(fd);
	open_file(&fd, file_name);
	ft_printf("*map size*\nheight:%i\nwidth:%i\n", game->map.height, game->map.width);
	load_map(game, fd);
	close(fd);
	check_map_validity(game, par);
	return (0);
}
