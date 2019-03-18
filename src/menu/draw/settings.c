/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_menu_settings(env_t *env)
{
    env->menu_s.s_set_circle[0] = sfSprite_create();
    env->menu_s.s_set_circle[1] = sfSprite_create();
    env->menu_s.s_set_circle[2] = sfSprite_create();
    env->menu_s.s_set_icon[0] = sfSprite_create();
    env->menu_s.s_set_icon[1] = sfSprite_create();
    env->menu_s.s_set_icon[2] = sfSprite_create();

    init_menu_settings_2(env);
    init_menu_settings_3(env);
}

void init_menu_settings_2(env_t *env)
{
    sfSprite_setTexture(env->menu_s.s_set_circle[0], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_circle[0],
    (sfIntRect) {151, 742, 126, 132});
    sfSprite_setPosition(env->menu_s.s_set_circle[0],
    (sfVector2f) {790.0, 485.0});

    sfSprite_setTexture(env->menu_s.s_set_circle[1], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_circle[1],
    (sfIntRect) {151, 742, 126, 132});
    sfSprite_setPosition(env->menu_s.s_set_circle[1],
    (sfVector2f) {955.0, 485.0});

    sfSprite_setTexture(env->menu_s.s_set_circle[2], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_circle[2],
    (sfIntRect) {151, 742, 126, 132});
    sfSprite_setPosition(env->menu_s.s_set_circle[2],
    (sfVector2f) {50.0, 800.0});
}

void init_menu_settings_3(env_t *env)
{
    sfSprite_setTexture(env->menu_s.s_set_icon[0], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_icon[0],
    (sfIntRect) {1938, 572, 53, 49});
    sfSprite_setPosition(env->menu_s.s_set_icon[0],
    (sfVector2f) {825.0, 525.0});

    sfSprite_setTexture(env->menu_s.s_set_icon[1], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_icon[1],
    (sfIntRect) {1086, 720, 40, 57});
    sfSprite_setPosition(env->menu_s.s_set_icon[1],
    (sfVector2f) {995.0, 520.0});

    sfSprite_setTexture(env->menu_s.s_set_icon[2], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->menu_s.s_set_icon[2],
    (sfIntRect) {2000, 517, 48, 47});
    sfSprite_setPosition(env->menu_s.s_set_icon[2],
    (sfVector2f) {95.0, 840.0});
}