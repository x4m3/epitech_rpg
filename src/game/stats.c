/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int get_money(env_t *env)
{
    return (env->game_s.money);
}

void set_money(env_t *env, int value)
{
    env->game_s.money = value;
    sfText_setString(env->game_s.text_money, my_itoa(env->game_s.money));
}

int get_level(env_t *env)
{
    return (env->game_s.level);
}

void set_level(env_t *env, int value)
{
    env->game_s.level = value;
    sfText_setString(env->game_s.text_level, my_itoa(env->game_s.level));
}