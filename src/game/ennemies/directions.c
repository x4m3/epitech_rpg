/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void ennemies_movement_right(env_t *env, int ennemies_id)
{
    set_ennemies_animation(env, ennemies_id);
    env->ennemies_s[ennemies_id].pos.x += 10 * env->core_s.delta_time;
    sfSprite_setPosition(env->ennemies_s[ennemies_id].s_ennemies,
    env->ennemies_s[ennemies_id].pos);
}

void ennemies_movement_left(env_t *env, int ennemies_id)
{
    set_ennemies_animation(env, ennemies_id);
    env->ennemies_s[ennemies_id].pos.x -= 10 * env->core_s.delta_time;
    sfSprite_setPosition(env->ennemies_s[ennemies_id].s_ennemies,
    env->ennemies_s[ennemies_id].pos);
}

void ennemies_movement_top(env_t *env, int ennemies_id)
{
    set_ennemies_animation(env, ennemies_id);
    env->ennemies_s[ennemies_id].pos.y -= 10 * env->core_s.delta_time;
    sfSprite_setPosition(env->ennemies_s[ennemies_id].s_ennemies,
    env->ennemies_s[ennemies_id].pos);
}

void ennemies_movement_down(env_t *env, int ennemies_id)
{
    set_ennemies_animation(env, ennemies_id);
    env->ennemies_s[ennemies_id].pos.y += 10 * env->core_s.delta_time;
    sfSprite_setPosition(env->ennemies_s[ennemies_id].s_ennemies,
    env->ennemies_s[ennemies_id].pos);
}