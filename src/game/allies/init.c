/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

int create_allies(env_t *env, int type, sfVector2f pos)
{
    int tmp = -1;
    if ((tmp = get_free_slot_allies(env)) == -1)
        return (-1);

    env->allies_s[tmp].is_valid = true;

    env->allies_s[tmp].bloons_hitted = 0;
    env->allies_s[tmp].type = type;
    env->allies_s[tmp].range = 150.0;

    env->allies_s[tmp].pos.x = pos.x;
    env->allies_s[tmp].pos.y = pos.y;

    env->allies_s[tmp].clock = sfClock_create();
    env->allies_s[tmp].c_hit = sfClock_create();
    env->allies_s[tmp].circle = sfCircleShape_create();
    env->allies_s[tmp].sprite = sfSprite_create();
    set_allies(env, tmp);
    return (0);
}

int get_free_slot_allies(env_t *env)
{
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (!env->allies_s[i].is_valid)
            return (i);
    }
    return (-1);
}

void delete_allies(env_t *env, int allies_id)
{
    if (env->allies_s[allies_id].is_valid) {
        sfClock_destroy(env->allies_s[allies_id].clock);
        sfClock_destroy(env->allies_s[allies_id].c_hit);
        sfSprite_destroy(env->allies_s[allies_id].sprite);
    }
    env->allies_s[allies_id].is_valid = false;
    env->allies_s[allies_id].bloons_hitted = 0;
    env->allies_s[allies_id].type = 0;

    env->allies_s[allies_id].pos.x = 0.0;
    env->allies_s[allies_id].pos.y = 0.0;
}