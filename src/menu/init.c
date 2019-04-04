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
    sfRenderWindow_clear(env->core_s.window, sfBlack);
    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
}