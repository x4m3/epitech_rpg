/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_mouse(env_t *env)
{
    env->game_s.s_mouse = sfSprite_create();
    sfSprite_setTexture(env->game_s.s_mouse, env->game_s.t_buttons[1], sfTrue);
    sfSprite_setOrigin(env->game_s.s_mouse, (sfVector2f) {92 / 2, 92 /2});

    env->game_s.s_mouse_circle = sfCircleShape_create();
    sfCircleShape_setRadius(env->game_s.s_mouse_circle, 150.0);
    sfCircleShape_setFillColor(env->game_s.s_mouse_circle, (sfColor) {
        245, 96, 93, 50
    });
    sfCircleShape_setOutlineColor(env->game_s.s_mouse_circle, (sfColor) {
        245, 96, 93, 150
    });
    sfCircleShape_setOutlineThickness(env->game_s.s_mouse_circle, 2.5);
    sfCircleShape_setOrigin(env->game_s.s_mouse_circle, (sfVector2f) {
        150.0, 150.0
    });
}