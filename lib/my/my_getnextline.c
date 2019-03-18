/*
** EPITECH PROJECT, 2018
** my_getnextline
** File description:
** Function that read a line
*/

#include "my.h"

char *read_line(char *line, int tmp, char *buffer, int *start)
{
    int oldlen = ((line != 0) ? my_strlen(line) : 0);
    char *newlen;

    if ((newlen = malloc(sizeof(char) * (oldlen + tmp + 1))) == NULL)
        return (NULL);

    if (line != 0)
        my_strncpy(newlen, line, oldlen);
    else
        my_strncpy(newlen, "", oldlen);

    newlen[oldlen + tmp] = '\0';
    my_strncpy(newlen + oldlen, buffer + *start, tmp);

    if (line)
        free(line);

    *start = *start + (tmp + 1);
    return (newlen);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE];
    static int tmp_buff = 0;
    static int start = 0;
    int tmp = 0;
    char *line = 0;

    for (;;) {
        if (tmp_buff <= start) {
            start = 0;
            if (!(tmp_buff = read(fd, buffer, READ_SIZE)))
                return (line);
            if (tmp_buff == -1)
                return (NULL);
            tmp = 0;
        }
        if (buffer[start + tmp] == '\n')
            return (line = read_line(line, tmp, buffer, &start));
        if (start + tmp == tmp_buff - 1)
            line = read_line(line, tmp + 1, buffer, &start);
        tmp++;
    }
}