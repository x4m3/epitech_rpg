/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_state(env_t *env)
{
    float tmp_delta[2];

    tmp_delta[0] = 0.0;
    env->core_s.clock = sfClock_create();

    while (sfRenderWindow_isOpen(env->core_s.window)) {
        events(env);
        check_buttons(env);
        if (env->core_s.actual_status == STATUS_MENU)
            game_menu(env);
        else if (env->core_s.actual_status == STATUS_PLAY)
            game_play(env);
        tmp_delta[1] = sfTime_asSeconds(sfClock_getElapsedTime(env->core_s.clock));
        env->core_s.delta_time = tmp_delta[1] - tmp_delta[0];
        tmp_delta[0] = tmp_delta[1];
    }
}