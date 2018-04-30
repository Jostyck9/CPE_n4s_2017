##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## UnitTest Makefile
##

SRC_DIR		=	$(realpath ..)

SRC		=	$(SRC_DIR)/sources/check_end.c	\

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/test_check_end.c		\

INC		=	-I ../include

OBJ		= 	$(SRC:%.c=%.o) $(SRC_UT:%.c=%.o)

CFLAGS		= 	$(INC) -Wall -Wextra --coverage

LDFLAGS		= 	-lcriterion -lgcov

CC		=	gcc

NAME		=	units

all		: 	$(NAME)

$(NAME)		: 	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(INC) $(LIBS)

clean		:
			rm -f $(OBJ)

fclean		: 	clean
			rm -f $(NAME)
			rm -f *.gcda
			rm -f *.gcno
			rm -f ../sources/*.gcda
			rm -f ../sources/*.gcno

re		: 	fclean all
