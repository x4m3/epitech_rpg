/*
** EPITECH PROJECT, 2018
** my_strupcase
** File description:
** Transform text to uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}
