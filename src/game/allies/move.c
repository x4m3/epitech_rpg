/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void move_allies(env_t *env)
{
    float angle = 0.0;

    for (int i = 0; i < MAX_ALLIES; i++) if (env->allies_s[i].is_valid) {
        int bloons_id = get_bloons_further(env, i);
        if (bloons_id == -1)
            continue;
        angle = get_angle(env->allies_s[i].pos, env->bloons_s[bloons_id].pos);
        sfSprite_setRotation(env->allies_s[i].sprite, angle);

    }
}

float get_angle(sfVector2f allies_pos, sfVector2f bloons_pos)
{
    float x_diff = bloons_pos.x - allies_pos.x;
    float y_diff = bloons_pos.y - allies_pos.y;

    return ((atan2(y_diff, x_diff)) * 180.0 / M_PI) + 90.0;
}