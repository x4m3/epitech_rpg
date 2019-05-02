/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static int get_free_slot_house(env_t *env)
{
    for (int i = 0; i < MAX_HOUSES; i++) {
        if (!env->houses_s[i].is_valid)
            return (i);
    }
    return (-1);
}

int get_max_house(env_t *env)
{
    int max_index = 0;
    for (size_t i = 0; i < MAX_HOUSES; i++) {
        if (env->houses_s[i].is_valid)
            max_index = i;
    }
    return (max_index);
}

void create_house(env_t *env, houses_t tmp_house)
{
    int tmp_id = -1;

    if ((tmp_id = get_free_slot_house(env)) == -1)
        return;

    env->houses_s[tmp_id].is_valid = true;

    env->houses_s[tmp_id].pos.x = tmp_house.pos.x;
    env->houses_s[tmp_id].pos.y = tmp_house.pos.y;

    env->houses_s[tmp_id].sprite = sfSprite_create();
    sfSprite_setTexture(env->houses_s[tmp_id].sprite, env->game_s.t_map,
    sfTrue);
    sfSprite_setTextureRect(env->houses_s[tmp_id].sprite,
    (sfIntRect) {1005, 0, 85, 138});
    sfSprite_setOrigin(env->houses_s[tmp_id].sprite,
    (sfVector2f) {85 / 2, 138 / 2});
    sfSprite_setPosition(env->houses_s[tmp_id].sprite,
    env->houses_s[tmp_id].pos);
}

void delete_house(env_t *env, int house_id)
{
    if (env->houses_s[house_id].is_valid)
        sfSprite_destroy(env->houses_s[house_id].sprite);

    env->houses_s[house_id].is_valid = false;

    env->houses_s[house_id].pos.x = 0.0;
    env->houses_s[house_id].pos.y = 0.0;
}