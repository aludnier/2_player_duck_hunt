##
## EPITECH PROJECT, 2024
## Makefile my_hunter
## File description:
## my_hunter
##

SRC	= 	src/window.c			\
		src/init.c			\
		src/destroy_all.c		\
		src/animation.c			\
		src/movement.c			\
		src/handle_event.c		\
		src/check_player_alive.c	\
		src/main.c			\
		src/help_display.c		\
		src/my_putstr.c			\
		src/my_putchar.c		\
		src/draw_sprite.c		\
		src/random_coordinate.c		\
		src/game_over.c			\

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_hunter

FLAG	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all : cc

cc :	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAG) -g3

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
