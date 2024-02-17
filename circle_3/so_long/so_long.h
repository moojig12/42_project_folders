/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:18 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:53:50 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./srcs/Libft/libft.h"
# include "./srcs/ft_printf/ft_printf.h"
# include "./srcs/get_next_line/get_next_line.h"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define SPACE 32
# define ENTER 65293
# define ESC 65307
# define TILE_SIZE 32

typedef struct map {
	int		height;
	int		width;
	int		map_number;
	char	**layout;
}				t_map;

typedef struct game {
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	t_map	map;
	int		last_movement;
	int		*player_pos;
	int		total_coins;
	int		movement;
	int		*pos;
	int		player_coins;
	int		*cd;
}				t_game;

// connection is to represent which sides are connected, 
// connection[0] = East, connection[1] = North,
// connection[2] = West, connection[3] = South

typedef struct sprites {
	int		width;
	int		height;
	int		*connection;
	void	*sprite;
	void	*next;
}				t_sprites;

typedef struct s_hook_params {
	t_game		*game;
	t_sprites	**sprites;
}				t_hook;

void	free_all(t_hook *par);
void	open_file(int *file, char *file_name);
int		ft_printf(const char *s1, ...);
int		parse_map(t_game *game, char *file_name, t_hook *par);
void	hooks(t_game *game, t_hook *hook_params);
void	init_screen(t_game *game);
void	load_sprites(t_game *game, t_sprites **sprites);
void	render(t_game *game);
void	render_map(t_game *game, t_sprites **sprites);
void	measure_game_screen(t_game *game);
void	player(t_game *game, t_sprites **sprites);
void	render_character(t_game *game, t_sprites **sprites);
void	check_wall_adjacency(t_game *game, int *adjacency, int x, int y);
int		movement(int keycode, t_hook *par);
void	put_wall(t_game *game, t_sprites **sprites, int y, int x);
void	put_grass(t_game *game, t_sprites **sprites, int y, int x);
void	put_enemy(t_game *game, t_sprites **sprites, int y, int x);
void	put_coin(t_game *game, t_sprites **sprites, int y, int x);
void	load(t_game *game, t_sprites *sprites, char *s);
void	load_slime(t_game *game, t_sprites **sprites, int *i);
void	check_sprite(void *sprite, int *i);
int		sl_strchr(const char *s, int c);
void	type_sprite(t_game *game, t_sprites *sprites, int x, int y);
void	lose(t_hook *par, int *pos);
void	give_coin(t_game *game);
void	win(t_hook *par, int *pos);
void	put_scoreboard(t_game *game, t_sprites **sprites);
void	put_exit(t_game *game, t_sprites **sprites, int y, int x);
void	filler_wall(t_game *game, t_sprites **sprites, int x, int y);
void	put_other_walls(t_game *game, t_sprites **sprites, int x, int y);
void	load_extra(t_game *game, t_sprites **sprites, int *i);
void	load_scoreboard(t_game *game, t_sprites **sprites, int *i);
void	border_error(t_game *g, int y, int x, t_hook *par);
void	check_map_validity(t_game *g, t_hook *par);
void	look_for_player(t_game *game);
void	update_pos(t_hook *par, int move, int y, int x);
void	update_right(t_hook *par, int y, int x, int *pos);
void	update_left(t_hook *par, int y, int x, int *pos);
void	update_down(t_hook *par, int y, int x, int *pos);
void	update_up(t_hook *par, int y, int x, int *pos);
void	free_par(t_hook *par);
void	free_gnl(char *line, int fd);

#endif