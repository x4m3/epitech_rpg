/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

const float ANIM_SPEED = 0.25;

void set_ennemies_rotation(env_t *env, int ennemies_id, int rotation)
{
    if (env->ennemies_s[ennemies_id].rotation == rotation)
        return;

    sfSprite_setTextureRect(env->ennemies_s[ennemies_id].s_ennemies, (sfIntRect) {
        env->ennemies_s[ennemies_id].tmp_animation * 32, rotation * 32, 32, 32
    });
    env->ennemies_s[ennemies_id].rotation = rotation;
}

void set_ennemies_animation(env_t *env, int ennemies_id)
{
    env->ennemies_s[ennemies_id].time_animation += env->core_s.delta_time;
    if (env->ennemies_s[ennemies_id].time_animation >= ANIM_SPEED) {
        env->ennemies_s[ennemies_id].time_animation = 0.0;
        if (env->ennemies_s[ennemies_id].tmp_animation >= 2)
        env->ennemies_s[ennemies_id].tmp_animation = 0;
        else
            env->ennemies_s[ennemies_id].tmp_animation++;

        sfSprite_setTextureRect(env->ennemies_s[ennemies_id].s_ennemies, (sfIntRect) {
            env->ennemies_s[ennemies_id].tmp_animation * 32, env->ennemies_s[ennemies_id].rotation * 32, 32, 32
        });
    }
}

void move_ennemies(env_t *env)
{
    sfVector2f go_to = env->game_s.p_character;

    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (!env->ennemies_s[i].is_valid)
            continue;
        if (env->ennemies_s[i].pos.x > go_to.x) {
            ennemies_movement_left(env, i);
        }
        else if (env->ennemies_s[i].pos.x < go_to.x)
            ennemies_movement_right(env, i);
        if (env->ennemies_s[i].pos.y > go_to.y)
            ennemies_movement_top(env, i);
        else if (env->ennemies_s[i].pos.y < go_to.y)
            ennemies_movement_down(env, i);
    }
}