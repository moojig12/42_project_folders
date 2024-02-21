@echo off

REM Variables
SET NAME=push_swap
SET CC=gcc
SET CFLAGS=-Wall -Werror -Wextra
SET LIBFT=.\srcs\Libft\*.c
SET SRCS=push_swap.c push_swap_utils.c swap_operations.c push_operations.c rotate_operations.c reverse_rotate_operations.c sort.c short_sort.c push_load.c

REM Targets

%CC% %CFLAGS% %SRCS% %LIBFT% -o %NAME%
