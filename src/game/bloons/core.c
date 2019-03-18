/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

int get_bloons_further(env_t *env, int allies_id)
{
    int index = -1;
    int max_distance = 0;

    for (int i = 0; i < MAX_BLOONS; i++) if (env->bloons_s[i].is_valid) {
        if (!check_collision(env, i, allies_id))
            continue;
        if (env->bloons_s[i].count_movements > max_distance) {
            max_distance = env->bloons_s[i].count_movements;
            index = i;
        }
    }
    return (index);
}