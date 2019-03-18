/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void events(env_t *env)
{
    while (sfRenderWindow_pollEvent(env->core_s.window, &env->core_s.event)) {
        if (env->core_s.event.type == sfEvtClosed)
            sfRenderWindow_close(env->core_s.window);

        if (env->core_s.actual_status == STATUS_MENU)
            menu_events(env);
        if (env->core_s.actual_status == STATUS_PLAY)
            game_events(env);
    }
}