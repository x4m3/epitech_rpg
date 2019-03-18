/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Function that concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *new_dest = dest;

    while (*dest)
        dest++;


    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return (new_dest);
}
