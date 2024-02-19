# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 13:33:00 by nmandakh          #+#    #+#              #
#    Updated: 2024/02/17 18:13:14 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBFT	= ./libraries/Libft/libft.a

PRINTF  = ./libraries/printf/printf.a

SRCS	= push_swap.c list_prep.c check.c utils.c \
swap_operations.c push_operations.c rotate_operations.c reverse_rotate_operations.c \
sort.c push_load.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/Libft
			make -C ./libraries/printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
			make clean -C ./libraries/Libft
			make clean -C ./libraries/printf
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re