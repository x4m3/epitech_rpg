/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** Function that converts and displays a decimal number into a num in a base
*/

#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int length = my_strlen(base);
    int tmp;

    if (nbr == 0)
        return (0);

    if (nbr < 0) {
        nbr *= -1;
        my_putchar('-');
    }
    else
        my_putnbr_base(nbr / length, base);

    tmp = nbr % length;
    my_putchar(base[tmp]);
    return (0);
}
