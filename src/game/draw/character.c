/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_character(env_t *env)
{
    env->game_s.t_character = sfTexture_createFromFile(GAME_CHARACTER, NULL);
    env->game_s.s_character = sfSprite_create();
    sfSprite_setTexture(env->game_s.s_character, env->game_s.t_character, sfTrue);
    sfSprite_setTextureRect(env->game_s.s_character, (sfIntRect) {0, 0, 32, 32});
    sfSprite_setOrigin(env->game_s.s_character, (sfVector2f) {32 / 2, 32 / 2});
    sfSprite_setScale(env->game_s.s_character, (sfVector2f) {1.2, 1.2});

    env->game_s.p_character = (sfVector2f) {1920 / 2, 1080 / 2};
}