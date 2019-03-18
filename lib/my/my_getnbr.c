/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Show all integrers in char
*/

#include "my.h"

int is_valid_int(long nb)
{
    if (nb > 2147483647 || nb < -2147483648)
        return (0);

    else
        return (nb);
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int specialchar = 1;

    if (my_strlen(str) > 12)
        return (0);

    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            continue;
        if (i > 0)
            specialchar = (str[i - 1] == '-') ? -1 : specialchar;
        if (str[i] >= '0' && str[i] <= '9')
            nb = ((nb * 10) + (str[i] - '0'));
        if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
            return (is_valid_int(nb * specialchar));
    }
    return (is_valid_int(nb * specialchar));
}
