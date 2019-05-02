/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static int get_collision_texture(sfIntRect rect)
{
    if ((rect.left == 280 && rect.top == 462)
    || (rect.left == 610 && rect.top == 0)
    || (rect.left == 676 && rect.top == 0)
    || (rect.left == 610 && rect.top == 66)
    || (rect.left == 676 && rect.top == 66)
    || (rect.left == 742 && rect.top == 66)
    || (rect.left == 610 && rect.top == 132)
    || (rect.left == 676 && rect.top == 132)
    || (rect.left == 742 && rect.top == 132)
    || (rect.left == 148 && rect.top == 396)
    || (rect.left == 214 && rect.top == 396)
    || (rect.left == 280 && rect.top == 396)
    || (rect.left == 280 && rect.top == 330))
        return (1);
    return (0);
}

int collision_circle(sfVector2f pos, sfCirclePos circle)
{
    int d2 = (pos.x - circle.x) * (pos.x - circle.x) +
    (pos.y - circle.y) * (pos.y - circle.y);

    if (d2 > circle.r * circle.r)
        return (false);
    else
        return (true);
}

int check_collision(env_t *env, sfVector2i move)
{
    sfVector2i pos = {
        (env->game_s.p_character.x + move.x) / 64,
        (env->game_s.p_character.y + move.y) / 64
    };
    sfIntRect rect = sfSprite_getTextureRect(env->game_s.s_map[pos.y][pos.x]);

    if (get_collision_texture(rect))
        return (1);
    return (0);
}