# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:17:12 by nmandakh          #+#    #+#              #
#    Updated: 2024/02/29 19:36:25 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & Flags
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

# Targets
SRCS		=	push_swap.c push_swap_utils.c push_load.c \
				sort.c sort_utils.c operations.c push_load_utils.c \
				sort_three.c sort_second.c sort_first.c sort_list_utils.c
LIBFT		=	./lib/Libft/libft.a
FT_PRINTF	=	./lib/ft_printf/libftprintf.a
STCK_OP		=	./operations/push_op.c ./operations/swap_op.c \
				./operations/rotate_op.c ./operations/reverse_op.c 

OBJS		=	$(SRCS=.c=.o)

# Program name
NAME	=	push_swap

all:	$(NAME)

$(NAME) : $(OBJS)
			make -C ./lib/Libft
			make bonus -C ./lib/Libft
			make -C ./lib/ft_printf
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) $(STCK_OP) -o $(NAME)

clean:
			make clean -C ./lib/Libft
			make clean -C ./lib/ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			make fclean -C ./lib/Libft
			make fclean -C ./lib/ft_printf
			rm -rf $(NAME)

re:			fclean all

update:		fclean
			make

norm:
			norminette $(srcs)

.PHONY = all clean fclean re update