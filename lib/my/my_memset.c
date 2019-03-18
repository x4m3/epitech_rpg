/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** Recode the function memset()
*/

#include "my.h"

char *my_memset(char *str, char c, int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
        str[i] = c;

    str[i] = '\0';
    return (str);
}