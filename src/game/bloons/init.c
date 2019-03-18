/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int create_bloons(env_t *env, int type)
{
    int tmp = -1;
    if ((tmp = get_free_slot_bloons(env)) == -1)
        return (-1);

    env->bloons_s[tmp].is_valid = true;
    env->bloons_s[tmp].speed = 2.5;
    env->bloons_s[tmp].i_pos = 0;
    env->bloons_s[tmp].count_movements = 0;

    env->bloons_s[tmp].pos.x = env->game_s.map[0][0];
    env->bloons_s[tmp].pos.y = env->game_s.map[0][1];

    env->bloons_s[tmp].clock = sfClock_create();
    env->bloons_s[tmp].sprite = sfSprite_create();

    draw_bloons(env, tmp);
    set_type_bloons(env, tmp, type);
    return (tmp);
}

void draw_bloons(env_t *env, int tmp)
{
    sfSprite_setTexture(env->bloons_s[tmp].sprite, env->game_s.t_icons,
    sfTrue);
    sfSprite_setTextureRect(env->bloons_s[tmp].sprite, (sfIntRect) {
        1375, 1083, 42, 58
    });
    sfSprite_setOrigin(env->bloons_s[tmp].sprite, (sfVector2f) {
        42 / 2, 58 / 2
    });
}

int get_free_slot_bloons(env_t *env)
{
    for (int i = 0; i < MAX_BLOONS; i++) {
        if (!env->bloons_s[i].is_valid)
            return (i);
    }
    return (-1);
}

void delete_bloons(env_t *env, int bloons_id)
{
    if (env->bloons_s[bloons_id].is_valid) {
        sfClock_destroy(env->bloons_s[bloons_id].clock);
        sfSprite_destroy(env->bloons_s[bloons_id].sprite);
    }
    env->bloons_s[bloons_id].is_valid = false;
    env->bloons_s[bloons_id].speed = 1.0;
    env->bloons_s[bloons_id].i_pos = 0;
    env->bloons_s[bloons_id].count_movements = 0;

    env->bloons_s[bloons_id].pos.x = 0;
    env->bloons_s[bloons_id].pos.y = 0;
}