##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Automatic compilation
##

NAME := 		my_rpg

INCLUDE :=	-I ./include/

SRC :=		my_rpg.c\
			src/window/events.c\
			src/window/game.c\
			src/window/init.c\
			src/window/sounds.c\
			src/utils/init_game.c\
			src/menu/draw/background.c\
			src/menu/draw/buttons.c\
			src/menu/draw/icons.c\
			src/menu/draw/settings.c\
			src/menu/buttons.c\
			src/menu/events.c\
			src/menu/init.c\
			src/menu/movements.c\
			src/game/allies/collision.c\
			src/game/allies/init.c\
			src/game/allies/move.c\
			src/game/allies/set.c\
			src/game/bloons/core.c\
			src/game/bloons/init.c\
			src/game/bloons/move.c\
			src/game/bloons/set.c\
			src/game/draw/init.c\
			src/game/draw/buttons.c\
			src/game/draw/mouse.c\
			src/game/draw/menu.c\
			src/game/draw/text.c\
			src/game/draw/ui.c\
			src/game/menu/init.c\
			src/game/menu/buttons.c\
			src/game/buttons.c\
			src/game/events.c\
			src/game/gameplay.c\
			src/game/hit.c\
			src/game/init.c\
			src/game/play.c\
			src/game/stats.c

OBJ :=		$(SRC:.c=.o)

LIB :=		-L ./lib/my/ -l my

CSFML :=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -pedantic -std=c99

LIBMATH :=	-lm

CFLAGS := 	-Wall -Wextra -g $(INCLUDE)

all:		$(NAME)

lib:
			make -C ./lib/my/ all

$(NAME): 	lib $(OBJ)
			gcc -o $(NAME) $(OBJ) $(CSFML) $(LIBMATH) $(LIB)


clean:
			make -C lib/my/ clean
			rm -rf $(OBJ)

fclean:		clean
			make -C lib/my/ fclean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all lib clean fclean re
