/*
** EPITECH PROJECT, 2018
** src/menu/draw/buttons
** File description:
** vim > emacs
*/

#include "my.h"
#include "my_rpg.h"

void init_menu_ui(env_t *env)
{
    env->menu_s.t_logo = sfTexture_createFromFile("assets/game_ui/menu/logo.png", NULL);
    env->menu_s.s_logo = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_logo, env->menu_s.t_logo, sfTrue);
}