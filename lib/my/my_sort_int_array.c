/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** Sorts an integer array in ascending order
*/

#include "my.h"

void my_sort_int_array(int *tab, int size)
{
    int check_size = 0;

    while (check_size < size) {
        my_sort_int_array(tab, size);
        check_size++;
    }
}

void my_sort_int_array_check(int *tab, int size)
{
    int nb = 0;
    while (nb < (size - 1)) {
        if (tab[nb] > tab[nb + 1]) {
            my_swap(&tab[nb], &tab[nb + 1]);
        }
        nb++;
    }
}
