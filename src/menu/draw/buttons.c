/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void init_menu_buttons(env_t *env)
{
    init_menu_buttons_2(env);

    env->menu_s.t_button[0] = sfTexture_createFromFile(_MENU_BTN_1, NULL);
    env->menu_s.t_button[1] = sfTexture_createFromFile(_MENU_BTN_2, NULL);
    env->menu_s.s_button[0] = sfSprite_create();
    env->menu_s.s_button[1] = sfSprite_create();
    env->menu_s.s_button[2] = sfSprite_create();

    sfSprite_setTexture(env->menu_s.s_button[0], env->menu_s.t_button[1],
    sfTrue);
    sfSprite_setPosition(env->menu_s.s_button[0], (sfVector2f) {660.0, 440.0});

    sfSprite_setTexture(env->menu_s.s_button[1], env->menu_s.t_button[0],
    sfTrue);
    sfSprite_setPosition(env->menu_s.s_button[1], (sfVector2f) {775.0, 540.0});

    sfSprite_setTexture(env->menu_s.s_button[2], env->menu_s.t_button[1],
    sfTrue);
    sfSprite_setPosition(env->menu_s.s_button[2], (sfVector2f) {660.0, 630.0});
}

void init_menu_buttons_2(env_t *env)
{
    int count_buttons = sizeof(env->menu_s.s_button) / sizeof(sfSprite *);

    for (int i = 0; i < count_buttons; i++) {
        env->menu_s.text_button[i] = sfText_create();
        sfText_setFont(env->menu_s.text_button[i], env->menu_s.font);
        sfText_setColor(env->menu_s.text_button[i],
        (sfColor) {245, 189, 0, 255});
        sfText_setOutlineColor(env->menu_s.text_button[i],
        (sfColor) {0, 0, 0, 255});
        sfText_setOutlineThickness(env->menu_s.text_button[i], 2.0);
    }

    sfText_setString(env->menu_s.text_button[0], "QUICK PLAY");
    sfText_setPosition(env->menu_s.text_button[0], (sfVector2f){850.0, 485.0});

    sfText_setString(env->menu_s.text_button[1], "LEAVE GAME");
    sfText_setPosition(env->menu_s.text_button[1], (sfVector2f){835.0, 580.0});

    sfText_setString(env->menu_s.text_button[2], "SETTINGS");
    sfText_setPosition(env->menu_s.text_button[2], (sfVector2f){860.0, 675.0});
}