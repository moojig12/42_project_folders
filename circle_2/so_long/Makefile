# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 16:49:11 by nmandakh          #+#    #+#              #
#    Updated: 2024/01/29 17:08:12 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -Imlx -g 
MLXFLAGS=	-L ./srcs/mlx -lmlx -lXext -lX11
LIBS	=	./srcs/Libft/libft.a
PRINTF  =  ./srcs/ft_printf/libftprintf.a

SRCS	=	main.c parse_map.c render_map.c \
			window_management.c player.c \
			render_character.c prepare_screen_size.c \
			map_render_border.c map_render_misc.c \
			map_render_walls.c error.c\
			load_sprites_scoreboard.c \
			load_sprites_extra.c check_format.c\
			load_sprites.c free.c check_map_free.c\
			render_score.c check_map_size.c\
			so_long_utils.c flood_fill.c\
			win_lose.c player_find.c player_directions.c \

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./srcs/mlx
			make -C ./srcs/Libft
			make -C ./srcs/ft_printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) $(PRINTF) -o $(NAME)

clean:
			make clean -C ./srcs/mlx
			make clean -C ./srcs/Libft
			make clean -C ./srcs/ft_printf
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

norm:
			norminette $(SRCS) so_long.h

.PHONY: all clean fclean re