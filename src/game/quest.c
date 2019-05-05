/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static const char *MESSAGE_START =
"Tu as vu juste!\n\n"\
"Detruit les ennemies avec\n"\
"la touche ESPACE.";

static int check_house_area(env_t *env)
{
    sfCirclePos circle;

    for (int i = 0; i < MAX_HOUSES; i++) {
        if (!env->houses_s[i].is_valid)
            continue;

        circle = (sfCirclePos) {
            env->houses_s[i].pos.x,
            env->houses_s[i].pos.y,
            150
        };

        if (collision_circle(env->game_s.p_character, circle))
            return (i);
    }
    return (-1);
}

static void check_must_spawn(env_t *env)
{
    sfTime tmp_time = sfClock_getElapsedTime(env->game_s.clock_spawn);
    float seconds = sfTime_asSeconds(tmp_time);

    if (env->game_s.must_spawn <= 0)
        return;
    if (env->game_s.house_id == -1)
        return;
    if (seconds > 1.5) {
        create_ennemies(env, env->houses_s[env->game_s.house_id].pos, 1);
        env->game_s.must_spawn--;
        sfClock_restart(env->game_s.clock_spawn);
    }
}

void check_quest(env_t *env)
{
    int house_id = check_house_area(env);
    if (house_id != -1 && count_ennemies(env) <= 0) {
        if (env->houses_s[house_id].is_attacked)
            return;
        env->game_s.house_id = house_id;
        env->houses_s[house_id].is_attacked = true;
        set_message(env, MESSAGE_START, 4);
        env->game_s.must_spawn = ((env->game_s.count_house + 1) * 3);
    }
    check_must_spawn(env);
}