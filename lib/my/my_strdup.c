/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** Function that allocates memory and copies the string given
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *new_src = NULL;

    if (!(new_src = malloc(sizeof(char) * (my_strlen(src) + 1))))
        return (NULL);

    my_strcpy(new_src, src);
    return (new_src);
}
