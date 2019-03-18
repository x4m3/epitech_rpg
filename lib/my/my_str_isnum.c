/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Function that return 1 if the parameter only contains digits. 0 otherwise
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}
