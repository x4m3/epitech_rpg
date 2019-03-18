/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** Reproduce the behavior of the strstr function
*/

#include "my.h"

int compare(const char *str, const char *to_find)
{
    int count_str = 0;
    int count_to_find = 0;

    while (str[count_str] && to_find[count_to_find]) {
        count_str++;
        count_to_find++;
    }
    return (to_find[count_to_find] == '\0');
}

char *my_strstr(char *str, char const *to_find)
{
    if (!*to_find)
        return (str);

    while (*str != '\0') {
        if ((*str == *to_find) && compare(str, to_find))
            return str;

        str++;
    }
    return (0);
}
