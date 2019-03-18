/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** Function that capitalizes the first letter of each word
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || i == 0)) {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
