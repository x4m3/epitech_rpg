/*
** EPITECH PROJECT, 2018
** project
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void display_help(char *argv[])
{
    char buffer[1];
    int fd = -1;
    if ((fd = open(HELP_FILE, O_RDONLY)) == -1)
        my_putstr("Error: can't find help file.\n");
    else {
        my_putstr("Usage: ");
        my_putstr(argv[0]);
        my_putstr(" <Parameters>\n");
        while (read(fd, buffer, 1) != 0)
            write(1, buffer, 1);
    }
}