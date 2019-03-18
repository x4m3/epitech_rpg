/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Same as my_strcmp function but compare at the n byte characters
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int value;
    int i = 0;

    while (*s1 - *s2 == 0 && i < n) {
        if (!*s1)
            break;
        s1++;
        s2++;
        i++;
    }
    value = (*s1 - *s2);
    return (value);
}
