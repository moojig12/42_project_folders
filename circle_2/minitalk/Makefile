# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 18:00:10 by nmandakh          #+#    #+#              #
#    Updated: 2024/03/04 11:40:04 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler & Flags
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

# Targets
C_SRCS	=	client.c
S_SRCS	=	server.c
LIBFT		=	./lib/Libft/libft.a
FT_PRINTF	=	./lib/ft_printf/libftprintf.a

OBJS_C	=	$(C_SRCS:.c=.o)
OBJS_C	=	$(S_SRCS:.c=.o)

# Program names
CLIENT	=	client
SERVER	=	server

all : $(CLIENT) $(SERVER)

# Compilation
$(CLIENT) : $(OBJS_C)
			make -C ./lib/Libft
			make -C ./lib/ft_printf
			$(CC) $(C_SRCS) $(LIBFT) $(FT_PRINTF) -o $(CLIENT)

$(SERVER) : $(OBJS_S)
			$(CC) $(S_SRCS) $(LIBFT) $(FT_PRINTF) -o $(SERVER)

clean:
			make clean -C ./lib/Libft
			make clean -C ./lib/ft_printf
			rm -rf $(OBJS_C) $(OBJS_S)
			
fclean:		clean
			make fclean -C ./lib/Libft
			make fclean -C ./lib/ft_printf
			rm -rf $(CLIENT) $(SERVER)

re:			fclean all

update:		fclean
			make

norm:
			norminette $(srcs)

.PHONY = all clean fclean re update