/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

int check_collision(env_t *env, int bloons_id, int allies_id)
{
    sfVector2i point = {
        (int) env->bloons_s[bloons_id].pos.x,
        (int) env->bloons_s[bloons_id].pos.y
    };

    sfCirclePos circle = {
        (int) env->allies_s[allies_id].pos.x,
        (int) env->allies_s[allies_id].pos.y,
        (int) env->allies_s[allies_id].range
    };

    if (collision_circle(point, circle))
        return (true);

    return (false);
}

int collision_circle(sfVector2i point, sfCirclePos circle)
{
    int d2 = (point.x - circle.x) * (point.x - circle.x) +
    (point.y - circle.y) * (point.y - circle.y);

    if (d2 > circle.r * circle.r)
        return (false);
    else
        return (true);
}