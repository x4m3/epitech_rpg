/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Count number of characters
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;

    return (i);
}
