##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## UnitTest Makefile
##

SRC_DIR		=	$(realpath ..)

SRC		=	$(SRC_DIR)/sources/check_end.c		\
			$(SRC_DIR)/sources/algo/check_if_ko.c	\
#			$(SRC_DIR)/sources/get_lidar.c		\
			$(SRC_DIR)/sources/sending_command.c	\
			$(SRC_DIR)/sources/printing_functions.c	\
			$(SRC_DIR)/sources/algo/algo.c		\
			$(SRC_DIR)/sources/algo/close_wall.c	\
			$(SRC_DIR)/sources/algo/update_car.c	\
			$(SRC_DIR)/sources/algo/speed.c		\
			$(SRC_DIR)/sources/algo/cost.c		\
			$(SRC_DIR)/sources/algo/direction.c	\
			$(SRC_DIR)/sources/main.c		\

SRC_UT_DIR	=	$(realpath .)

SRC_UT		=	$(SRC_UT_DIR)/test_check_end.c		\
			$(SRC_UT_DIR)/test_check_if_ko.c	\

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
			rm -f ../sources/algo/*.gcda
			rm -f ../sources/algo/*.gcno

re		: 	fclean all
