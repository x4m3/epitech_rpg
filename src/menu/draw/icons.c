/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void init_menu_icons(env_t *env)
{
    env->menu_s.t_icons[0] = sfTexture_createFromFile(_MENU_ICONS_1, NULL);
    env->menu_s.t_icons[1] = sfTexture_createFromFile(_MENU_ICONS_2, NULL);
    env->menu_s.s_icons[0] = sfSprite_create();
    env->menu_s.s_icons[1] = sfSprite_create();
    env->menu_s.s_icons[2] = sfSprite_create();

    init_menu_icons_2(env);
}

void init_menu_icons_2(env_t *env)
{
    sfSprite_setTexture(env->menu_s.s_icons[0], env->menu_s.t_icons[0],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_icons[0],
    (sfIntRect) {1781, 1233, 61, 56});
    sfSprite_setPosition(env->menu_s.s_icons[0],
    (sfVector2f) {690.0, 485.0});

    sfSprite_setTexture(env->menu_s.s_icons[1], env->menu_s.t_icons[0],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_icons[1],
    (sfIntRect) {1418, 1632, 69, 62});
    sfSprite_setPosition(env->menu_s.s_icons[1],
    (sfVector2f) {1170.0, 575.0});

    sfSprite_setTexture(env->menu_s.s_icons[2], env->menu_s.t_icons[0],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_icons[2],
    (sfIntRect) {983, 1791, 80, 74});
    sfSprite_setPosition(env->menu_s.s_icons[2], (sfVector2f) {683.0, 665.0});
}