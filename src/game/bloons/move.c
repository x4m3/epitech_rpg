/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void bloons_move(env_t *env)
{
    for (int i = 0; i < MAX_BLOONS; i++) {
        if (!env->bloons_s[i].is_valid)
            continue;

        sfTime time = sfClock_getElapsedTime(env->bloons_s[i].clock);
        if ((time.microseconds * env->bloons_s[i].speed) / 20000 > 1.0) {
            bloons_set_position(env, i);
            sfClock_restart(env->bloons_s[i].clock);
        }
    }
}

void bloons_set_position(env_t *env, int id)
{
    int index_pos = env->bloons_s[id].i_pos;
    if (env->bloons_s[id].pos.x > env->game_s.map[index_pos][0])
        env->bloons_s[id].pos.x -= (1.0);
    else if (env->bloons_s[id].pos.x < env->game_s.map[index_pos][0])
        env->bloons_s[id].pos.x += (1.0);
    if (env->bloons_s[id].pos.y > env->game_s.map[index_pos][1])
        env->bloons_s[id].pos.y -= (1.0);
    else if (env->bloons_s[id].pos.y < env->game_s.map[index_pos][1])
        env->bloons_s[id].pos.y += (1.0);

    sfSprite_setPosition(env->bloons_s[id].sprite, (sfVector2f) {
        env->bloons_s[id].pos.x,
        env->bloons_s[id].pos.y
    });
    check_index_pos(env, id);
    env->bloons_s[id].count_movements++;
}

void check_index_pos(env_t *env, int id)
{
    int index_pos = env->bloons_s[id].i_pos;
    sfVector2f bloons_p = env->bloons_s[id].pos;
    sfVector2i game_p = {
        env->game_s.map[index_pos][0],
        env->game_s.map[index_pos][1]
    };

    if (bloons_p.x == game_p.x && bloons_p.y == game_p.y) {
        if (env->game_s.map[index_pos + 1] == NULL) {
            delete_bloons(env, id);
            env->game_s.health--;
            if (env->game_s.health <= 0)
                env->game_s.is_gameover = true;
        }
        else {
            env->bloons_s[id].i_pos++;
        }
    }
}

int in_range(int value, int min, int max)
{
    if (value >= min && value <= max)
        return (1);

    return (0);
}