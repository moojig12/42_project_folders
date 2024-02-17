/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:37:29 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:59:39 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		ft_printf("map line number %i:%s\n", i + 1, game->map.layout[i]);
		i++;
	}
	ft_printf("\n");
}

void	run_game(t_hook *par, char *file_name)
{
	parse_map(par->game, file_name, par);
	print_map(par->game);
	measure_game_screen(par->game);
	init_screen(par->game);
	load_sprites(par->game, par->sprites);
	render_map(par->game, par->sprites);
	player(par->game, par->sprites);
	hooks(par->game, par);
	mlx_loop(par->game->mlx);
}

int	main(int argc, char **argv)
{
	t_sprites	**sprites;
	t_game		*game;
	t_hook		*par;
	int			i;

	i = 0;
	if (argc != 2)
	{
		perror("Error, Invalid number of arguments! :(\n");
		return (1);
	}
	par = (t_hook *)malloc(sizeof(t_hook));
	game = malloc(sizeof(t_game));
	sprites = malloc(41 * sizeof(t_sprites *));
	while (i <= 40)
	{
		sprites[i] = malloc(sizeof(t_sprites));
		i++;
	}
	par->game = game;
	par->sprites = sprites;
	game->last_movement = 0;
	game->movement = 0;
	game->player_pos = NULL;
	game->player_coins = 0;
	run_game(par, argv[1]);
	return (0);
}
