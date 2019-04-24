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

static int check_house_collision(env_t *env, sfVector2i move)
{
    sfVector2i pos = {
        (env->game_s.p_character.x + move.x),
        (env->game_s.p_character.y + move.y)
    };

    for (int i = 0; i < MAX_HOUSES; i++) if (env->houses_s[i].is_valid) {
        sfFloatRect bounds = sfSprite_getGlobalBounds(env->houses_s[i].sprite);
        if (sfFloatRect_contains(&bounds, pos.x, pos.y))
            return (i);
    }
    return (-1);
}

int check_collision(env_t *env, sfVector2i move)
{
    int house_id = -1;
    sfVector2i pos = {
        (env->game_s.p_character.x + move.x) / 64,
        (env->game_s.p_character.y + move.y) / 64
    };
    sfIntRect rect = sfSprite_getTextureRect(env->game_s.s_map[pos.y][pos.x]);

    if (get_collision_texture(rect))
        return (1);
    if ((house_id = check_house_collision(env, move)) != -1) {
        printf("Enter in collision with house ID: %d\n", house_id);
        return (1);
    }
    return (0);
}