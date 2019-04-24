/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_events(env_t *env)
{
    if (env->core_s.event.type == sfEvtKeyPressed) {
        if (env->core_s.event.key.code == sfKeyDown)
            char_movement_down(env);
        if (env->core_s.event.key.code == sfKeyUp)
            char_movement_top(env);
        if (env->core_s.event.key.code == sfKeyLeft)
            char_movement_left(env);
        if (env->core_s.event.key.code == sfKeyRight)
            char_movement_right(env);
        if (env->core_s.event.key.code == sfKeySpace)
            printf("[DEBUG] Character position (%0.2f, %0.2f)\n",
            env->game_s.p_character.x, env->game_s.p_character.y);
    }
}