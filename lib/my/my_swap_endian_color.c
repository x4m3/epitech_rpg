/*
** EPITECH PROJECT, 2018
** my_swap_endian_color
** File description:
** Function that changes the endianness of the color and return it
*/

#include "my.h"

int my_swap_endian_color(int color)
{
    int red;
    int green;
    int blue;
    int alpha;

    red = (color >> 24) & 0xFF;
    green = (color >> 16) & 0xFF;
    blue = (color >> 8) & 0xFF;
    alpha = color & 0xFF;

    return ((alpha << 24) | (blue << 16) | (green << 8) | red);
}
