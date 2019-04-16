/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void set_character_rotation(env_t *env, int rotation)
{
    if (env->game_s.rotation == rotation)
        return;

    sfSprite_setTextureRect(env->game_s.s_character, (sfIntRect) {
        env->game_s.tmp_animation * 32, rotation * 32, 32, 32
    });
    env->game_s.rotation = rotation;
}

void set_character_animation(env_t *env)
{
    if (env->game_s.tmp_animation >= 2)
        env->game_s.tmp_animation = 0;
    else
        env->game_s.tmp_animation++;

    sfSprite_setTextureRect(env->game_s.s_character, (sfIntRect) {
        env->game_s.tmp_animation * 32, env->game_s.rotation * 32, 32, 32
    });

}