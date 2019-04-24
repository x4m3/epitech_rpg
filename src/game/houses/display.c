/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void display_houses(env_t *env)
{
    for (int i = 0; i < MAX_HOUSES; i++) if (env->houses_s[i].is_valid) {
        sfRenderWindow_drawSprite(
            env->core_s.window,
            env->houses_s[i].sprite,
            NULL);
    }
}