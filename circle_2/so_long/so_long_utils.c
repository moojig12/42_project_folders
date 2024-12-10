/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:47:43 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 15:47:39 by nmandakh         ###   ########.fr       */
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
		ft_printf("Map could not be opened");
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

void	count_coins(t_hook *par, int *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	par->game->total_coins = 0;
	while (i < par->game->map.height)
	{
		while (j < par->game->map.width)
		{
			if (par->game->map.buff[i][j] == 'C')
				par->game->total_coins++;
			check_for_invalid_char(par->game->map.buff[i][j], par, pos);
			j++;
		}
		j = 0;
		i++;
	}
}

char	**duplicate_map(t_hook *par)
{
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(par->game->map.height * sizeof(char *));
	while (i < par->game->map.height)
	{
		result[i] = ft_strdup(par->game->map.layout[i]);
		i++;
	}
	return (result);
}
