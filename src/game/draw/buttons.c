/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_buttons(env_t *env)
{
    game_draw_buttons_1(env);
    game_draw_buttons_2(env);
}

void game_draw_buttons_1(env_t *env)
{
    int count_text_price = sizeof(env->game_s.text_price) / sizeof(sfText *);
    for (int i = 0; i < count_text_price; i++) {
        env->game_s.text_price[i] = sfText_create();
        sfText_setFont(env->game_s.text_price[i], env->menu_s.font);
        sfText_setColor(env->game_s.text_price[i], (sfColor) {
            245, 189, 0, 255
        });
        sfText_setOutlineColor(env->game_s.text_price[i], (sfColor) {
            0, 0, 0, 255
        });
        sfText_setOutlineThickness(env->game_s.text_price[i], 2.0);
        sfText_setCharacterSize(env->game_s.text_price[i], 20);
        sfText_setPosition(env->game_s.text_price[i], (sfVector2f) {
            1130.0 + (115 * i), 1053.0
        });
        sfText_setString(env->game_s.text_price[i], env->game_s.price[i]);
    }
}

void game_draw_buttons_2(env_t *env)
{
    int count_buttons = sizeof(env->game_s.s_button) / sizeof(sfSprite *);
    for (int i = 0; i < (int) count_buttons; i++) {
        env->game_s.s_button[i] = sfSprite_create();
        sfSprite_setTexture(env->game_s.s_button[i], env->game_s.t_buttons[0],
        sfTrue);
        sfSprite_setTextureRect(env->game_s.s_button[i], (sfIntRect) {
            92 * i, 0, 92, 92
        });
        sfSprite_setPosition(env->game_s.s_button[i], (sfVector2f) {
            1106 + ((92 + 25) * i), 964
        });
    }
}