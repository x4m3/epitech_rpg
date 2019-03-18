/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** Function that display the number given as a parameter
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }

    if (nb / 10 != 0)
        my_putnbr(nb / 10);

    my_putchar((nb % 10) + '0');
    return (0);
}
