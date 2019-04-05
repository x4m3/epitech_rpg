/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void on_menu_button_hitted(env_t *env)
{
    if (get_button_by_text(env, "settings"))
        env->menu_s.actual_status = M_STATUS_SETTINGS;
    if (get_button_by_text(env, "howto"))
        env->menu_s.actual_status = M_STATUS_HOWTO;
    if (get_button_by_text(env, "play"))
        env->core_s.actual_status = STATUS_PLAY;
}