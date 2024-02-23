@echo off

REM Targets
SET	NAME=push_swap
SET	CC=gcc
SET	CFLAGS=-Wall -Werror -Wextra -g

SET	SRCS=*.c
SET	LIBFT=./srcs/Libft/*.c
SET LST=./lst_functions/*.c
SET	OP=./operations/*.c

%CC% %CFLAGS% %SRCS% %LIBFT% %LST% %OP% -o %NAME%