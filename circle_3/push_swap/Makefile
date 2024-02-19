# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 13:33:00 by nmandakh          #+#    #+#              #
#    Updated: 2024/02/19 19:29:46 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g

LIBFT	= ./srcs/Libft/libft.a

PRINTF  = ./srcs/ft_printf/printf.a

SRCS	= push_swap.c push_swap_utils.c \
swap_operations.c push_operations.c rotate_operations.c reverse_rotate_operations.c \
sort.c short_sort.c push_load.c

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./srcs/Libft
			make bonus -C ./srcs/Libft
			make -C ./srcs/ft_printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
			make clean -C ./srcs/Libft
			make clean -C ./srcs/ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			make fclean -C ./srcs/Libft
			make fclean -C ./srcs/ft_printf
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re