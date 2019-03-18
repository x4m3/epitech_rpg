/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void set_allies(env_t *env, int id)
{
    sfIntRect rect_allies;
    if (env->allies_s[id].type == ALLIES_MONKEY)
        rect_allies = (sfIntRect) {1946, 695, 72, 85};
    if (env->allies_s[id].type == ALLIES_WIZARD)
        rect_allies = (sfIntRect) {1235, 1308, 77, 84};
    if (env->allies_s[id].type == ALLIES_BOOMRANG)
        rect_allies = (sfIntRect) {1660, 1022, 74, 74};

    draw_allies(env, id);
    draw_allies_2(env, id, rect_allies);
}

void draw_allies(env_t *env, int id)
{
    sfCircleShape_setPosition(env->allies_s[id].circle, (sfVector2f) {
        env->allies_s[id].pos.x,
        env->allies_s[id].pos.y
    });
    sfCircleShape_setRadius(env->allies_s[id].circle, 150.0);
    sfCircleShape_setFillColor(env->allies_s[id].circle, (sfColor) {
        245, 96, 93, 50
    });
    sfCircleShape_setOutlineColor(env->allies_s[id].circle, (sfColor) {
        245, 96, 93, 150
    });
    sfCircleShape_setOutlineThickness(env->allies_s[id].circle, 2.5);
    sfCircleShape_setOrigin(env->allies_s[id].circle, (sfVector2f) {
        env->allies_s[id].range,
        env->allies_s[id].range
    });
}

void draw_allies_2(env_t *env, int id, sfIntRect rect_allies)
{
    sfSprite_setPosition(env->allies_s[id].sprite, (sfVector2f) {
        env->allies_s[id].pos.x,
        env->allies_s[id].pos.y
    });
    sfSprite_setTexture(env->allies_s[id].sprite, env->game_s.t_characters,
    sfTrue);
    sfSprite_setTextureRect(env->allies_s[id].sprite, rect_allies);
    sfSprite_setOrigin(env->allies_s[id].sprite, (sfVector2f) {72 / 2, 85 / 2});
}