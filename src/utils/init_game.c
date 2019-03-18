/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void reset_var(env_t *env)
{
    for (int i = 0; i < MAX_BLOONS; i++) {
        env->bloons_s[i].is_valid = false;
        delete_bloons(env, i);
    }

    for (int i = 0; i < MAX_ALLIES; i++) {
        env->allies_s[i].is_valid = false;
        delete_allies(env, i);
    }
}