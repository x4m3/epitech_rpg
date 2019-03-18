/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void generate_level_bloons(env_t *env, int max_bloons)
{
    int bloons_gived = 0;
    for (int i = 0; i < COUNT_TYPE_BLOONS; i++) {
        if (env->game_s.level > 10 && i == BLOONS_BLACK) {
            env->game_s.bloons_needed[i] = ((max_bloons - bloons_gived) / 10);
            bloons_gived += ((max_bloons - bloons_gived) / 10);
        }
        if (env->game_s.level > 6 && i == BLOONS_GREEN) {
            env->game_s.bloons_needed[i] = ((max_bloons - bloons_gived) / 8);
            bloons_gived += ((max_bloons - bloons_gived) / 8);
        }
        if (env->game_s.level > 4 && i == BLOONS_PINK) {
            env->game_s.bloons_needed[i] = ((max_bloons - bloons_gived) / 6);
            bloons_gived += ((max_bloons - bloons_gived) / 6);
        }
        if (env->game_s.level > 2 && i == BLOONS_BLUE) {
            env->game_s.bloons_needed[i] = ((max_bloons - bloons_gived) / 6);
            bloons_gived += ((max_bloons - bloons_gived) / 6);
        }
    }
    env->game_s.bloons_needed[BLOONS_RED] = (max_bloons - bloons_gived);
    bloons_gived += (max_bloons - bloons_gived);
}

void generate_bloons(env_t *env)
{
    sfTime time = sfClock_getElapsedTime(env->game_s.c_generate_bloons);
    if ((time.microseconds / (300000 / (env->game_s.level / 10.0))) > 1.0) {
        int bloons_type = get_type_free_bloons(env);
        create_bloons(env, bloons_type);
        sfClock_restart(env->game_s.c_generate_bloons);
    }
}

int get_type_free_bloons(env_t *env)
{
    int type_bloons = -1;

    if (check_is_free_bloons(env) == 0) {
        set_level(env, env->game_s.level + 1);
        for (int i = 0; i < COUNT_TYPE_BLOONS; i++)
            env->game_s.bloons_needed[i] = 0;
        generate_level_bloons(env, 30 * (env->game_s.level * 0.5));
    }
    while (1) {
        int tmp = rand() % COUNT_TYPE_BLOONS;
        if (env->game_s.bloons_needed[tmp] > 0) {
            type_bloons = tmp;
            env->game_s.bloons_needed[tmp]--;
            break;
        }
    }
    return (type_bloons);
}

int check_is_free_bloons(env_t *env)
{
    for (int i = 0; i < COUNT_TYPE_BLOONS; i++) {
        if (env->game_s.bloons_needed[i] > 0)
            return (1);
    }
    return (0);
}