/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void move_ennemies(env_t *env)
{
    sfVector2f go_to = env->game_s.p_character;

    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (!env->ennemies_s[i].is_valid)
            continue;
        printf("ennemies %d\n", i);
        if (env->ennemies_s[i].pos.x > go_to.x) {
            printf("BEFORE: %0.2f\n", env->ennemies_s[i].pos.x);
            env->ennemies_s[i].pos.x -= 10 * env->core_s.delta_time;
            printf("AFTER: %0.2f\n", env->ennemies_s[i].pos.x);
        }
        else if (env->ennemies_s[i].pos.x < go_to.x) {
            printf("BEFORE: %0.2f\n", env->ennemies_s[i].pos.x);
            env->ennemies_s[i].pos.x += 10 * env->core_s.delta_time;
            printf("AFTER: %0.2f\n", env->ennemies_s[i].pos.x);
        }
        if (env->ennemies_s[i].pos.y > go_to.y)
            env->ennemies_s[i].pos.y -= 10 * env->core_s.delta_time;
        else if (env->ennemies_s[i].pos.y < go_to.y)
            env->ennemies_s[i].pos.y += 10 * env->core_s.delta_time;
        sfSprite_setPosition(env->ennemies_s[i].s_ennemies, env->ennemies_s[i].pos);
    }
}