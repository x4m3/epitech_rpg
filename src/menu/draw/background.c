/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void init_menu_background(env_t *env)
{
    env->menu_s.t_background[0] =
    sfTexture_createFromFile(_MENU_BACKGROUND, NULL);
    env->menu_s.t_background[1] =
    sfTexture_createFromFile(_MENU_SKYEFFECTS, NULL);
    env->menu_s.t_sky[0] = sfTexture_createFromFile(_MENU_SKY_1, NULL);
    env->menu_s.t_sky[1] = sfTexture_createFromFile(_MENU_SKY_2, NULL);

    init_menu_background_2(env);
    init_menu_background_3(env);
}

void init_menu_background_2(env_t *env)
{
    env->menu_s.s_sky[0] = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_sky[0], env->menu_s.t_sky[0], sfTrue);
    sfSprite_setPosition(env->menu_s.s_sky[0], (sfVector2f) {-1500.0, 0.0});

    env->menu_s.s_sky[1] = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_sky[1], env->menu_s.t_sky[1], sfTrue);
}

void init_menu_background_3(env_t *env)
{
    env->menu_s.s_background[0] = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_background[0],
    env->menu_s.t_background[1], sfTrue);
    sfSprite_setOrigin(env->menu_s.s_background[0],
    (sfVector2f) {1920.0 * 0.5, 1080.0 * 0.5});
    sfSprite_setPosition(env->menu_s.s_background[0],
    (sfVector2f) {1920.0 * 0.5, 1080.0 * 0.7});
    sfSprite_setScale(env->menu_s.s_background[0], (sfVector2f) {2.3, 2.3});

    env->menu_s.s_background[1] = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_background[1],
    env->menu_s.t_background[0], sfTrue);
}