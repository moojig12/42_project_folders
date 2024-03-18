@echo off

REM Targets
SET	NAME=push_swap
SET	CC=gcc
SET	CFLAGS= -g

SET	SRCS=*.c
SET	LIBFT=./lib/Libft/*.c
SET	OP=./operations/*.c

%CC% %CFLAGS% %SRCS% %LIBFT% %LST% %OP% -o %NAME%