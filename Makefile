#
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	sources/main.c \
<<<<<<< HEAD
		sources/printing_functions.c	\
		sources/check_end.c
=======
		sources/printing_functions.c \
		sources/sending_command.c \
>>>>>>> 744cae854d84ff9af4d526d8c77ef6aff3346914

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
