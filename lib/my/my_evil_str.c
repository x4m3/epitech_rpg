/*
** EPITECH PROJECT, 2018
** my_evil_str
** File description:
** Swap all characters. The first to the last one, etc...
*/

#include "my.h"

char *my_evil_str(char *str)
{
    int tmp;
    int size = my_strlen(str);

    for (int i = 0; i < size / 2; i++) {
        tmp = str[i];
        str[i] = str[(size - 1) - i];
        str[(size - 1) - i] = tmp;
    }
    return (str);
}
