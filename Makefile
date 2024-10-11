CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ftprintf_fctarg1.c ftprintf_fctarg2.c\
OBJ = ${SRC:.c=.o}
RM = rm -f
AR = ar rcs

all : ${NAME}
	
