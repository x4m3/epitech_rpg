/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Check if two string in parameters was same
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int value;

    while (*s1 - *s2 == 0) {
        if (!*s1)
            break;
        s1++;
        s2++;
    }
    value = (*s1 - *s2);

    if (value >= 1)
        return (1);

    else if (value <= -1)
        return (-1);

    else
        return (value);
}
