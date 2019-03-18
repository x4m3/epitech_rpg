/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void game_state(env_t *env)
{
    while (sfRenderWindow_isOpen(env->core_s.window)) {
        events(env);

        if (env->core_s.actual_status == STATUS_MENU)
            game_menu(env);
        else if (env->core_s.actual_status == STATUS_PLAY)
            game_play(env);
    }
}