/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:37:29 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/29 17:04:36 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		ft_printf("map line number %i:%s\n", i + 1, game->map.layout[i]);
		i++;
	}
	ft_printf("\n");
} */
	// print_map(par->game);

void	run_game(t_hook *par, char *file_name)
{
	parse_map(par->game, file_name, par);
	measure_game_screen(par->game);
	init_screen(par->game);
	load_sprites(par->game, par->sprites);
	render_map(par->game, par->sprites);
	player(par->game, par->sprites);
	hooks(par->game, par);
	mlx_loop(par->game->mlx);
}

void	initialize_main(t_hook *par, t_game *game, t_sprites **sprites)
{
	par->game = game;
	par->sprites = sprites;
	par->game->last_movement = 0;
	par->game->movement = 0;
	par->game->player_pos = NULL;
	par->game->player_coins = 0;
}

int	main(int argc, char **argv)
{
	t_sprites	**sprites;
	t_game		*game;
	t_hook		*par;
	int			i;

	if (argc != 2)
	{
		ft_printf("Error, Invalid number of arguments! :(\n");
		return (1);
	}
	check_format(argv[1]);
	i = 0;
	par = (t_hook *)malloc(sizeof(t_hook));
	game = malloc(sizeof(t_game));
	sprites = malloc(41 * sizeof(t_sprites *));
	while (i <= 40)
	{
		sprites[i] = malloc(sizeof(t_sprites));
		i++;
	}
	initialize_main(par, game, sprites);
	run_game(par, argv[1]);
	return (0);
}
