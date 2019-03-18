/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Function that copies n characters from a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return (dest);
}
