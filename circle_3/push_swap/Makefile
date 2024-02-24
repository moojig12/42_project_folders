# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:17:12 by nmandakh          #+#    #+#              #
#    Updated: 2024/02/24 12:36:10 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & Flags
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

# Targets
SRCS		=	push_swap.c push_swap_utils.c push_load.c \
				sort.c
LIBFT		=	./srcs/Libft/libft.a
FT_PRINTF	=	./srcs/ft_printf/libftprintf.a
LST_FT		=	./lst_functions/list_functions.c
STCK_OP		=	./operations/push_op.c ./operations/swap_op.c \
				./operations/rotate_op.c ./operations/reverse_op.c 


OBJS		=	$(SRCS=.c=.o)

# Program name
NAME	=	push_swap

all:	$(NAME)

$(NAME) : $(OBJS)
			make -C ./srcs/Libft
			make -C ./srcs/ft_printf
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) $(STCK_OP) $(LST_FT) -o $(NAME)

clean:
			make clean -C ./srcs/Libft
			make clean -C ./srcs/ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			make fclean -C ./srcs/Libft
			make fclean -C ./srcs/ft_printf
			rm -rf $(NAME)

re:			fclean all

update:		fclean
			make

.PHONY = all clean fclean re update