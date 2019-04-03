/*
** EPITECH PROJECT, 2018
** project
** File description:
** Prototypes of all functions in the program
*/

#pragma once

#include <math.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct s_character
{
    int life;
    int mana;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
}

typedef enum s_pos {
    UP;
    DOWN;
    LEFT;
    RIGHT;
    OFF;
}pos_t;
