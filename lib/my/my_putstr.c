/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Display one by one the characters of a string
*/

#include "my.h"

int my_putstr(char const * str)
{
    write(1, str, my_strlen(str));
    return (1);
}
