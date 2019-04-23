/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void char_movement_right(env_t *env)
{
    sfVector2f pos = sfView_getCenter(env->game_s.view);

    set_character_rotation(env, ROTATION_RIGHT);
    if (check_collision(env, (sfVector2i) {4, 0}))
        return;
    if (pos.x < (env->game_s.map_size.width - (1920 / 2) * 0.6)
    && pos.x == env->game_s.p_character.x)
        sfView_move(env->game_s.view, (sfVector2f) {4, 0});
    set_character_animation(env);
    env->game_s.p_character.x += 4;
}

void char_movement_left(env_t *env)
{
    sfVector2f pos = sfView_getCenter(env->game_s.view);

    set_character_rotation(env, ROTATION_LEFT);
    if (check_collision(env, (sfVector2i) {-4, 0}))
        return;
    if (pos.x > (1920 / 2) * 0.6
    && pos.x == env->game_s.p_character.x)
        sfView_move(env->game_s.view, (sfVector2f) {-4, 0});
    set_character_animation(env);
    env->game_s.p_character.x -= 4;
}

void char_movement_top(env_t *env)
{
    sfVector2f pos = sfView_getCenter(env->game_s.view);

    set_character_rotation(env, ROTATION_UP);
    if (check_collision(env, (sfVector2i) {0, -4}))
        return;
    if (pos.y > (1080 / 2) * 0.6
    && pos.y == env->game_s.p_character.y)
        sfView_move(env->game_s.view, (sfVector2f) {0, -4});
    set_character_animation(env);
    env->game_s.p_character.y -= 4;
}

void char_movement_down(env_t *env)
{
    sfVector2f pos = sfView_getCenter(env->game_s.view);

    set_character_rotation(env, ROTATION_DOWN);
    if (check_collision(env, (sfVector2i) {0, 4}))
        return;
    if (pos.y < (env->game_s.map_size.height - (1080 / 2) * 0.6)
    && pos.y == env->game_s.p_character.y)
        sfView_move(env->game_s.view, (sfVector2f) {0, 4});
    set_character_animation(env);
    env->game_s.p_character.y += 4;
}