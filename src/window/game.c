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
    while (sfRenderWindow_isOpen(env->core_s.window)) {
        events(env);
        check_buttons(env);
        if (env->core_s.actual_status == STATUS_MENU)
            game_menu(env);
    }
}