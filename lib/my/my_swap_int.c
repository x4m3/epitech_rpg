/*
** EPITECH PROJECT, 2018
** my_swap_int
** File description:
** Swap the content of two integers
*/

#include "my.h"

void my_swap_int(int a, int b)
{
    int swap1;
    int swap2;

    swap1 = a;
    swap2 = b;

    a = swap2;
    b = swap1;
}
