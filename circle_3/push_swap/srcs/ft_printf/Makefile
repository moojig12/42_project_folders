# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:19:30 by nmandakh          #+#    #+#              #
#    Updated: 2023/12/06 16:32:58 by nmandakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_print_char.c ft_print_string.c ft_print_digit.c \
			ft_print_pointer.c ft_printf.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -I.

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
fclean:		clean
				$(RM) $(NAME)
re:				fclean $(NAME)

.PHONY:		all clean fclean re bonus