##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Automatised compilation
##

NAME = 		libmy.a

SRC	=		my_atoi.c\
			my_concat_params.c\
			my_error.c\
			my_evil_str.c\
			my_get_color.c\
			my_getnbr.c\
			my_getnextline.c\
			my_is_prime.c\
			my_memset.c\
			my_printf.c\
			my_putchar.c\
			my_putnbr_base.c\
			my_putnbr.c\
			my_putstr.c\
			my_revstr.c\
			my_show_word_array.c\
			my_sort_int_array.c\
			my_sort_word_array.c\
			my_str_isnum.c\
			my_str_to_word_array.c\
			my_strcapitalize.c\
			my_strcat.c\
			my_strcmp.c\
			my_strcpy.c\
			my_strdup.c\
			my_strlen.c\
			my_strlowcase.c\
			my_strncat.c\
			my_strncmp.c\
			my_strncpy.c\
			my_strstr.c\
			my_strupcase.c\
			my_swap_endian_color.c\
			my_swap_int.c\
			my_swap.c

OBJ := 		$(SRC:.c=.o)

INCLUDE :=	-I ./include/

CFLAGS :=	-Wall -g $(INCLUDE)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			ar rc $(NAME) $(OBJ)
			mkdir -p ../../include/
			cp ./include/my.h ../../include/my.h

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
