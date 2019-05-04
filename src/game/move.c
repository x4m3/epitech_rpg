/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static const float CHARACTER_SPEED = 4.0;

void char_movement_right(env_t *env)
{
    env->game_s.timer = sfClock_getElapsedTime(env->game_s.clock);
    if (sfTime_asSeconds(env->game_s.timer)
    >= sfTime_asSeconds(sfSeconds(0.1))) {
        sfVector2f pos = sfView_getCenter(env->game_s.view);

        set_character_rotation(env, ROTATION_RIGHT);
        if (check_collision(env, (sfVector2i) {CHARACTER_SPEED, 0}))
            return;
        if (pos.x < (env->game_s.map_size.width - (1920 / 2) * 0.6)
        && pos.x == env->game_s.p_character.x)
            sfView_move(env->game_s.view, (sfVector2f) {CHARACTER_SPEED, 0});
        if (env->game_s.p_character.x + (32 / 2) < env->game_s.map_size.width)
        {
            set_character_animation(env);
            env->game_s.p_character.x += CHARACTER_SPEED;
        }
        sfClock_restart(env->game_s.clock);
        env->game_s.timer = sfTime_Zero;
    }
}

void char_movement_left(env_t *env)
{
    env->game_s.timer = sfClock_getElapsedTime(env->game_s.clock);
    if (sfTime_asSeconds(env->game_s.timer)
    >= sfTime_asSeconds(sfSeconds(0.1))) {
        sfVector2f pos = sfView_getCenter(env->game_s.view);

        set_character_rotation(env, ROTATION_LEFT);
        if (check_collision(env, (sfVector2i) {-CHARACTER_SPEED, 0}))
            return;
        if (pos.x > (1920 / 2) * 0.6
        && pos.x == env->game_s.p_character.x)
            sfView_move(env->game_s.view, (sfVector2f) {-CHARACTER_SPEED, 0});
        if (env->game_s.p_character.x - (32 / 2) > 0) {
            set_character_animation(env);
            env->game_s.p_character.x -= CHARACTER_SPEED;
        }
        sfClock_restart(env->game_s.clock);
        env->game_s.timer = sfTime_Zero;
    }
}

void char_movement_top(env_t *env)
{
    env->game_s.timer = sfClock_getElapsedTime(env->game_s.clock);
    if (sfTime_asSeconds(env->game_s.timer)
    >= sfTime_asSeconds(sfSeconds(0.1))) {
        sfVector2f pos = sfView_getCenter(env->game_s.view);

        set_character_rotation(env, ROTATION_UP);
        if (check_collision(env, (sfVector2i) {0, -CHARACTER_SPEED}))
            return;
        if (pos.y > (1080 / 2) * 0.6
        && pos.y == env->game_s.p_character.y)
            sfView_move(env->game_s.view, (sfVector2f) {0, -CHARACTER_SPEED});
        if (env->game_s.p_character.y - (32 / 2) > 0) {
            set_character_animation(env);
            env->game_s.p_character.y -= CHARACTER_SPEED;
        }
        sfClock_restart(env->game_s.clock);
        env->game_s.timer = sfTime_Zero;
    }
}

void char_movement_down(env_t *env)
{
    env->game_s.timer = sfClock_getElapsedTime(env->game_s.clock);
    if (sfTime_asSeconds(env->game_s.timer)
    >= sfTime_asSeconds(sfSeconds(0.1))) {
        sfVector2f pos = sfView_getCenter(env->game_s.view);

        set_character_rotation(env, ROTATION_DOWN);
        if (check_collision(env, (sfVector2i) {0, CHARACTER_SPEED}))
            return;
        if (pos.y < (env->game_s.map_size.height - (1080 / 2) * 0.6)
        && pos.y == env->game_s.p_character.y)
            sfView_move(env->game_s.view, (sfVector2f) {0, CHARACTER_SPEED});
        if (env->game_s.p_character.y + (32 / 2) < env->game_s.map_size.height)
        {
            set_character_animation(env);
            env->game_s.p_character.y += CHARACTER_SPEED;
        }
        sfClock_restart(env->game_s.clock);
        env->game_s.timer = sfTime_Zero;
    }
}