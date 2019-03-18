/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void check_hit(env_t *env)
{
    for (int i = 0; i < MAX_ALLIES; i++) if (env->allies_s[i].is_valid) {
        sfTime time = sfClock_getElapsedTime(env->allies_s[i].c_hit);
        if ((time.microseconds / 500000) > 1.0) {
            check_hit_allies(env, i);
            sfClock_restart(env->allies_s[i].c_hit);
        }
    }
}

void check_hit_allies(env_t *env, int allies_id)
{
    int bloons_id = -1;

    if ((bloons_id = get_bloons_further(env, allies_id)) != -1)
        bloons_hit(env, bloons_id, allies_id);
}

void bloons_hit(env_t *env, int bloons_id, int allies_id)
{
    env->allies_s[allies_id].bloons_hitted++;

    if (env->bloons_s[bloons_id].type > 0) {
        set_type_bloons(env, bloons_id, env->bloons_s[bloons_id].type - 1);
    }
    else {
        set_money(env, env->game_s.money + 5);
        delete_bloons(env, bloons_id);
    }
}