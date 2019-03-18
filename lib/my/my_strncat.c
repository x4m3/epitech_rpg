/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** Function that concatenates n characters from two strings
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    char *new_dest = dest;
    int i = 0;

    while (*dest)
        dest++;

    while (*src && i < nb) {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = '\0';
    return (new_dest);
}
