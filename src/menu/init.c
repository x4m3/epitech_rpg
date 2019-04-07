/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_menu(env_t *env)
{
    if (env->menu_s.actual_status == M_STATUS_MAIN)
        game_menu_draw(env);
    else if (env->menu_s.actual_status == M_STATUS_SETTINGS)
        game_menu_draw_settings(env);
}