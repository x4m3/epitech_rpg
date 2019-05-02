/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_pause_draw(env_t *env)
{
    env->game_s.txt_pause = sfText_create();
    sfText_setFont(env->game_s.txt_pause, env->core_s.f_oetz);
    sfText_setCharacterSize(env->game_s.txt_pause, 150);
    sfText_setColor(env->game_s.txt_pause, (sfColor) {245, 189, 0, 255});
    sfText_setOutlineColor(env->game_s.txt_pause,
    (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(env->game_s.txt_pause, 2.0);
}