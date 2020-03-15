##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## My_Hunter
##

SRC	=	src/display.c		\
		src/game.c		\
		src/game_ai.c		\
		src/line.c		\
		src/main.c		\
		src/utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall -Wextra -Iinc 

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
