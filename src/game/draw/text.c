/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void draw_game_text(env_t *env)
{
    sfText_setFont(env->game_s.text_money, env->menu_s.font);
    sfText_setColor(env->game_s.text_money, (sfColor) {245, 189, 0, 255});
    sfText_setOutlineColor(env->game_s.text_money, (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(env->game_s.text_money, 2.0);
    sfText_setCharacterSize(env->game_s.text_money, 28);
    sfText_setPosition(env->game_s.text_money, (sfVector2f) {
        910.0, 923.0
    });
    sfText_setString(env->game_s.text_money, my_itoa(env->game_s.money));

    sfText_setFont(env->game_s.text_level, env->menu_s.font);
    sfText_setColor(env->game_s.text_level, (sfColor) {245, 189, 0, 255});
    sfText_setOutlineColor(env->game_s.text_level, (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(env->game_s.text_level, 2.0);
    sfText_setCharacterSize(env->game_s.text_level, 28);
    sfText_setPosition(env->game_s.text_level, (sfVector2f) {
        910.0, 985.0
    });
    sfText_setString(env->game_s.text_level, my_itoa(env->game_s.level));
}