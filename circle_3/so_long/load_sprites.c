/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:48:45 by nmandakh          #+#    #+#             */
/*   Updated: 2024/01/23 15:30:58 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load(t_game *game, t_sprites *sprites, char *s)
{
	sprites->sprite = mlx_xpm_file_to_image(game->mlx, s, \
	&sprites->width, &sprites->height);
}

void	check_sprite(void *sprite, int *i)
{
	if (!sprite)
		(*i)++;
}

void	load_walls1(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[0], "./textures/walls/top_wall.xpm");
	check_sprite(sprites[0]->sprite, i);
	load(game, sprites[1], "./textures/walls/right_wall.xpm");
	check_sprite(sprites[1]->sprite, i);
	load(game, sprites[2], "./textures/walls/bottom_wall.xpm");
	check_sprite(sprites[2]->sprite, i);
	load(game, sprites[3], "./textures/walls/left_wall.xpm");
	check_sprite(sprites[3]->sprite, i);
	load(game, sprites[4], "./textures/walls/mid_cwall.xpm");
	check_sprite(sprites[4]->sprite, i);
	load(game, sprites[5], "./textures/walls/grass.xpm");
	check_sprite(sprites[5]->sprite, i);
	load(game, sprites[6], "./textures/walls/topleft_cwall.xpm");
	check_sprite(sprites[6]->sprite, i);
	load(game, sprites[7], "./textures/walls/top_cwall.xpm");
	check_sprite(sprites[7]->sprite, i);
	load(game, sprites[8], "./textures/walls/topright_cwall.xpm");
	check_sprite(sprites[8]->sprite, i);
	load(game, sprites[9], "./textures/walls/right_cwall.xpm");
	check_sprite(sprites[9]->sprite, i);
}

void	load_walls2(t_game *game, t_sprites **sprites, int *i)
{
	load(game, sprites[10], "./textures/walls/bottomright_cwall.xpm");
	check_sprite(sprites[10]->sprite, i);
	load(game, sprites[11], "./textures/walls/bottom_cwall.xpm");
	check_sprite(sprites[11]->sprite, i);
	load(game, sprites[12], "./textures/walls/bottomleft_cwall.xpm");
	check_sprite(sprites[12]->sprite, i);
	load(game, sprites[13], "./textures/walls/left_cwall.xpm");
	check_sprite(sprites[13]->sprite, i);
	load(game, sprites[14], "./textures/walls/single_wall.xpm");
	check_sprite(sprites[14]->sprite, i);
	load(game, sprites[15], "./textures/walls/vert_wall.xpm");
	check_sprite(sprites[15]->sprite, i);
	load(game, sprites[16], "./textures/walls/hori_wall.xpm");
	check_sprite(sprites[16]->sprite, i);
}

void	load_sprites(t_game *game, t_sprites **sprites)
{
	int	i;

	i = 0;
	load_walls1(game, sprites, &i);
	load_walls2(game, sprites, &i);
	load_slime(game, sprites, &i);
	load_extra(game, sprites, &i);
	load_scoreboard(game, sprites, &i);
	if (i > 0)
	{
		perror("Error loading assets.\n");
		exit(0);
	}
}
