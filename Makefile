##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Automatic compilation
##

NAME := 		my_rpg

INCLUDE :=	-I ./include/

SRC :=		my_rpg.c\
			src/game/draw/character.c\
			src/game/draw/game_ui.c\
			src/game/draw/inventory.c\
			src/game/draw/pause.c\
			src/game/draw/quest.c\
			src/game/draw/view.c\
			src/game/ennemies/directions.c\
			src/game/ennemies/fight.c\
			src/game/ennemies/init.c\
			src/game/ennemies/move.c\
			src/game/houses/display.c\
			src/game/houses/init.c\
			src/game/character.c\
			src/game/collision.c\
			src/game/events.c\
			src/game/game.c\
			src/game/gameover.c\
			src/game/init.c\
			src/game/inventory.c\
			src/game/message.c\
			src/game/move.c\
			src/game/pause.c\
			src/game/quest.c\
			src/game/timers.c\
			src/map/init.c\
			src/map/check.c\
			src/map/texture.c\
			src/menu/draw/how_to.c\
			src/menu/draw/menu_ui.c\
			src/menu/draw/settings.c\
			src/menu/events.c\
			src/menu/how_to.c\
			src/menu/init.c\
			src/menu/main.c\
			src/menu/settings.c\
			src/utils/help/display.c\
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
