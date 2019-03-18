/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Function that splits a string into words
*/

#include "my.h"

int count_word(char const *str)
{
    int count = 0;

    if (my_strlen(str) >= 1)
        count++;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == ' ')
            count++;
    }
    return (count);
}

char** arr_alloc(size_t x, size_t y)
{
    char** pp = malloc(sizeof(*pp) * x);

    for (size_t i = 0; i < x; i++) {
        pp[i] = malloc(sizeof(**pp) * y);
    }
    return (pp);
}

char **my_str_to_word_array(char const *str)
{
    char **final_string;
    int k = 0;
    int tmp = 0;
    final_string = arr_alloc(count_word(str), 50);

    for (int i = 0; i < my_strlen(str); i++) {
        final_string[k][tmp] = str[i];
        tmp++;
        if (str[i] == ' ') {
            k++;
            tmp = 0;
        }
    }
    return (final_string);
}
