/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void game_draw_ui(env_t *env)
{
    env->game_s.s_ui = sfSprite_create();
    sfSprite_setTexture(env->game_s.s_ui, env->game_s.t_ui, sfTrue);

    env->game_s.s_map[0] = sfSprite_create();
    sfSprite_setTexture(env->game_s.s_map[0], env->game_s.t_map[0], sfTrue);

    env->game_s.s_icons = sfSprite_create();
    sfSprite_setTexture(env->game_s.s_icons, env->game_s.t_icons, sfTrue);
    sfSprite_setTextureRect(env->game_s.s_icons, (sfIntRect) {
        1375, 1083, 42, 58
    });
}