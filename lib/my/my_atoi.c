/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** Function that convert int into a string
*/

#include "my.h"

char *my_itoa(int number)
{
    char *str;
    int length = 0;
    int tmp = number;

    while (tmp > 0) {
        tmp /= 10;
        length++;
    }
    str = malloc(sizeof(*str) * (length + 1));
    str[length] = '\0';
    while (length--) {
        str[length] = number % 10 + '0';
        number /= 10;
    }
    return (str);
}