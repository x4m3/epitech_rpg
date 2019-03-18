/*
** EPITECH PROJECT, 2018
** my_error
** File description:
** Function that write on output error and return 84
*/

#include "my.h"

int send_error(char *c)
{
    write(2, c, my_strlen(c));
    return (84);
}