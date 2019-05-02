/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_quest(env_t *env)
{
    env->game_s.clock_spawn = sfClock_create();
    sfClock_restart(env->game_s.clock_spawn);
}