##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Automatic compilation
##

NAME := 		my_rpg

INCLUDE :=	-I ./include/

SRC :=		my_rpg.c\
			src/menu/draw/buttons.c \
			src/menu/events.c \
			src/menu/setting.c\
			src/menu/init.c\
			src/window/buttons/animation.c\
			src/window/buttons/display.c\
			src/window/buttons/event.c\
			src/window/buttons/init.c\
			src/window/events.c\
			src/window/game.c\
			src/window/init.c

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
