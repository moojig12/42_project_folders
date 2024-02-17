/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:43 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:34:58 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_validity(t_game *g, t_hook *par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->map.height)
	{
		while (j < g->map.width)
		{
			border_error(g, i, j, par);
			j++;
		}
		i++;
		j = 0;
	}
}

void	open_file(int *file, char *file_name)
{
	(*file) = open(file_name, O_RDONLY);
	if ((*file) == -1)
		perror("Map could not be opened");
	return ;
}

int	sl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}
