#
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main.c \
		sources/my_printf.c \
		sources/needs_for_my_printf.c \
		sources/my_put_nbr.c \
		sources/my_getnbr.c 

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

INC	=	-I./include

CFLAGS	=	$(INC) -Wextra -Wall 

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

tests_run :
			make -C tests/
			./units

tests_fclean :
				make fclean -C tests/

debug: 		CFLAGS += -g
debug:		re
