# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 16:49:11 by nmandakh          #+#    #+#              #
#    Updated: 2024/01/23 15:29:52 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = srcs/ft_printf/ft_print_char.c \
		srcs/ft_printf/ft_print_digit.c \
		srcs/ft_printf/ft_print_pointer.c \
		srcs/ft_printf/ft_print_string.c \
		srcs/ft_printf/ft_printf.c
GNL = srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c
LIBFT = srcs/Libft/ft_strlen.c \
		srcs/Libft/ft_strdup.c srcs/Libft/ft_itoa.c
SRCS =  main.c parse_map.c render_map.c \
		window_management.c player.c \
		render_character.c prepare_screen_size.c \
		map_render_border.c map_render_misc.c \
		map_render_walls.c \
		load_sprites_scoreboard.c \
		load_sprites_extra.c \
		load_sprites.c free.c \
		render_score.c \
		so_long_utils.c \
		win_lose.c player_find.c player_directions.c \
		$(GNL) $(LIBFT) $(PRINTF)
SRCS_NORM = main.c parse_map.c render_map.c \
		window_management.c player.c \
		render_character.c prepare_screen_size.c \
		map_render_border.c map_render_misc.c \
		map_render_walls.c \
		load_sprites_scoreboard.c \
		load_sprites_extra.c \
		load_sprites.c free.c \
		render_score.c \
		so_long_utils.c \
		win_lose.c player_find.c player_directions.c
OBJS = $(SRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./srcs/minilibx-linux/ -lmlx -lXext -lX11 -lm
RM = rm -f

NAME = game

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
fclean: clean
			$(RM) $(NAME)
re: fclean
			$(NAME)

norm:
	norminette $(SRCS_NORM)