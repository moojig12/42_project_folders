/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:46:58 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 16:55:19 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	insert_first_check(t_game *game, char *line)
{
	if (sl_strchr(line, '\n'))
		line[sl_strchr(line, '\n')] = 0;
	game->map.width = ft_strlen(line);
}

static void	check_not_same(char *line, t_hook *par, int fd)
{
	if (((ft_strlen(line)) != par->game->map.width))
	{
		ft_printf("Map has inproper dimensions\n");
		free_gnl(line, fd);
		free_check(par);
		exit (0);
	}
}

void	check_map_size(t_game *game, int fd, t_hook *par)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	insert_first_check(game, line);
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
		if (line)
			if (sl_strchr(line, '\n'))
				line[sl_strchr(line, '\n')] = 0;
		if (!line)
			break ;
		check_not_same(line, par, fd);
		game->map.width = ft_strlen(line);
	}
	game->map.height = height;
	if (line)
		free(line);
}
