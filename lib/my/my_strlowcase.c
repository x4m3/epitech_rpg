/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** Transform text to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        i++;
    }
    return (str);
}
