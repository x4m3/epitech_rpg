/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg.h"

pos_t get_input(void)
{
    pos_t res = OFF;

    (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) ? (res = UP) : (0);
    (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) ? (res = DOWN) : (0);
    (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) ? (res = LEFT) : (0);
    (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) ? (res = RIGHT) : (0);
    return (res);
}
