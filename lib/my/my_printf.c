/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Recode the printf() function of C library
*/

#include "my.h"

int check_nextchar(char c)
{
    switch (c) {
    case '%':
        return (1);
    case '\0':
        return (1);
    case '\n':
        return (1);
    }
    return (0);
}

void my_printf_address(int nbr)
{
    if (nbr == 0) {
        my_putstr("(nil)");
    }

    my_putstr("0x");
    my_putnbr_base(nbr, "0123456789abcdef");
}

void my_printf(const char *str, ...)
{
    va_list va;
    va_start(va, str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == '%' && (str[i + 1] != '%' || str[i + 1] != '\0')) {
            display_params(va, str[i + 1]);
            i++;
        }
        else {
            my_putchar(str[i]);
        }
    }

    va_end(va);
}

void display_params(va_list va, char str)
{
    if (str == 'c')
        my_putchar(va_arg(va, int));

    if (str == 'd' || str == 'i')
        my_putnbr(va_arg(va, int));

    if (str == 'x' || str == 'X')
        my_putnbr_base(va_arg(va, int), "0123456789abcdef");

    if (str == 'o')
        my_putnbr_base(va_arg(va, int), "01234567");

    if (str == 'b')
        my_putnbr_base(va_arg(va, int), "01");

    if (str == 'p')
        my_printf_address(va_arg(va, int));
}