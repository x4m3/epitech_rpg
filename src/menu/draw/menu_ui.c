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
    env->menu_s.t_logo = sfTexture_createFromFile(MENU_LOGO, NULL);
    env->menu_s.s_logo = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_logo, env->menu_s.t_logo, sfTrue);
    sfSprite_setScale(env->menu_s.s_logo, (sfVector2f) {0.5, 0.5});
    sfSprite_setPosition(env->menu_s.s_logo, (sfVector2f) {615.0, 100.0});

    env->menu_s.t_background = sfTexture_createFromFile(MENU_BACKGROUND, NULL);
    env->menu_s.s_background = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_background, env->menu_s.t_background, sfTrue);
}