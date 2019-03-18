/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** Return true if the number is prome and false if not
*/

#include "my.h"

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);

    for (int i = 2; i <= nb / 2; i++) {
        if (nb %i == 0)
            return (0);
    }
    return (1);
}
