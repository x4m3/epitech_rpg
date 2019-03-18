/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Function that allocates memory and copies the string given
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *new_src;

    new_src = malloc(sizeof(src));
    my_strcpy(new_src, src);

    return new_src;
}
