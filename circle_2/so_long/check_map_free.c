/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:29:17 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:55 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_check(t_hook *par)
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
