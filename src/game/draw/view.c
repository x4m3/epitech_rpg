/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_view(env_t *env)
{
    env->game_s.view = sfView_create();
    sfView_setSize(env->game_s.view, (sfVector2f) {1920, 1080});
    sfView_setCenter(env->game_s.view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_zoom(env->game_s.view, 0.6);
}