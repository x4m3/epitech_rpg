/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static int get_slowest_index(env_t *env)
{
    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (!env->ennemies_s[i].is_valid)
            return (i);
    }
    return (-1);
}

void create_ennemies(env_t *env, sfVector2f pos, int type)
{
    (void) type;
    int id = get_slowest_index(env);
    if (id == -1)
        return;

    env->ennemies_s[id].is_valid = true;
    env->ennemies_s[id].health = 100.0;
    env->ennemies_s[id].time_animation = 0.0;
    env->ennemies_s[id].pos = pos;

    env->ennemies_s[id].s_ennemies = sfSprite_create();
    sfSprite_setTexture(env->ennemies_s[id].s_ennemies, env->game_s.t_character,
    sfTrue);
    sfSprite_setTextureRect(env->ennemies_s[id].s_ennemies,
    (sfIntRect) {0, 0, 32, 32});
    sfSprite_setOrigin(env->ennemies_s[id].s_ennemies,
    (sfVector2f) {32 / 2, 32 / 2});
    sfSprite_setPosition(env->ennemies_s[id].s_ennemies,
    env->ennemies_s[id].pos);
}

void delete_enemmies(env_t *env, int ennemies_id)
{
    if (env->ennemies_s[ennemies_id].is_valid)
        sfSprite_destroy(env->ennemies_s[ennemies_id].s_ennemies);

    env->ennemies_s[ennemies_id].is_valid = false;
    env->ennemies_s[ennemies_id].health = 100.0;

    env->ennemies_s[ennemies_id].pos.x = 0.0;
    env->ennemies_s[ennemies_id].pos.y = 0.0;
}


size_t count_ennemies(env_t *env)
{
    size_t count = 0;
    for (size_t i = 0; i < MAX_ENNEMIES; i++) {
        if (env->ennemies_s[i].is_valid)
            count++;
    }
    return (count);
}

void display_ennemies(env_t *env)
{
    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (env->ennemies_s[i].is_valid)
            sfRenderWindow_drawSprite(
                env->core_s.window,
                env->ennemies_s[i].s_ennemies,
                NULL);
    }
}