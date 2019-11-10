##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_printf
##

NAME	=	libmy.a

SRC	=	lib/my/my_printf.c \
		lib/my/my_putchar.c \
		lib/my/my_putstr.c \
		lib/my/my_strlen.c \
		lib/my/my_put_nbr.c \
		lib/my/my_strcpy.c \
		lib/my/error_handling.c \
		lib/my/gest_flag.c \
		lib/my/display_with_flag.c

CC	=	gcc

AR	=	ar rc

DEFLAGS	=	-W -Wextra -Wall -g3

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include -lcriterion

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)

build 	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

unit_test	:
		$(CC) -o unit_tests lib/my/*.c $(CFFLAGS) 

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *# \
		rm -f *~

re	:	fclean all

.PHONY	:	all build unit_test clean fclean re
