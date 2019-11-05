##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_printf
##

NAME	=	libmy.a

SRC	=	src/main.c \
		src/disp_stdarg.c \
		src/sum_stdarg.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/my_strlen.c \
		src/my_put_nbr.c

CC	=	gcc

CPPFLAGS	=	-I./include/

CFFLAGS	=	-W -Wextra -Wall -g3

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *# \
		rm -f *~

re	:	fclean all

.PHONY	:	all clean fclean re
