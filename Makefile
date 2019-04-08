##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Automatic compilation
##

NAME := 		my_rpg

INCLUDE :=	-I ./include/

SRC :=		my_rpg.c\
			src/game/draw/game_ui.c\
			src/game/events.c\
			src/game/game.c\
			src/game/init.c\
			src/menu/draw/how_to.c\
			src/menu/draw/menu_ui.c\
			src/menu/draw/settings.c\
			src/menu/events.c\
			src/menu/how_to.c\
			src/menu/init.c\
			src/menu/main.c\
			src/menu/settings.c\
			src/window/buttons/animation.c\
			src/window/buttons/display.c\
			src/window/buttons/event.c\
			src/window/buttons/init.c\
			src/window/events.c\
			src/window/fonts.c\
			src/window/game.c\
			src/window/init.c\
			src/window/sounds.c

OBJ :=		$(SRC:.c=.o)

LIB :=		-L ./lib/my/ -l my

CSFML :=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -pedantic -std=c99

LIBMATH :=	-lm

CFLAGS := 	-Wall -Wextra -g $(INCLUDE)

all:		$(NAME)

lib:
			make -C ./lib/my/ all

$(NAME): 	lib $(OBJ)
			gcc -o $(NAME) $(OBJ) $(CSFML) $(LIB)


clean:
			make -C lib/my/ clean
			rm -rf $(OBJ)

fclean:		clean
			make -C lib/my/ fclean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all lib clean fclean re
