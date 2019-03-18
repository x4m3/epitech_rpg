/*
** EPITECH PROJECT, 2018
** my_concat_params
** File description:
** Function that turn command-line into a single string
*/

#include "my.h"

char *my_concat_params(int argc, char **argv)
{
    int i = 0;
    char *final_string = malloc(sizeof(char) * (argc + 1));

    if (!final_string)
        return (0);

    for (i = 0; i < argc; i++) {
        my_strcat(final_string, argv[i]);

        if (i != argc - 1)
            my_strcat(final_string, "\n");
    }
    final_string[my_strlen(final_string) + 1] = '\0';
    return (final_string);
}
