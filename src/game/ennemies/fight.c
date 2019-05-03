/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static const char* MESSAGE_WIN =
"Felicitation, tu as trouve\n\
un objet.\n\n\
Il a ete ajoute a ton\n\
inventaire ('i').";

static const char* MESSAGE_END =
"FELICITATION!\n\n\
Tu as trouve toutes les\n\
objets voles.\n\
Le jeu est termine, mais tu\n\
peux te balader a ta guise.";

static int check_collision_ennemies(env_t *env, int ennemies_id)
{
    sfVector2f pos = env->game_s.p_character;
    sfCirclePos circle = {
        env->ennemies_s[ennemies_id].pos.x,
        env->ennemies_s[ennemies_id].pos.y,
        50
    };
    if (collision_circle(pos, circle))
        return (true);

    return (false);
}

static void send_fight_ennemies(env_t *env, int ennemies_id)
{
    env->ennemies_s[ennemies_id].health -= 50;
    if (env->ennemies_s[ennemies_id].health <= 0) {
        delete_enemmies(env, ennemies_id);
        if (count_ennemies(env) <= 0) {
            add_item_user(env);
            set_message(env, MESSAGE_WIN, 8);
            env->game_s.house_id++;
        }
        if (env->game_s.house_id > get_max_house(env))
            set_message(env, MESSAGE_END, 5);
    }
}

static void send_fight_player(env_t *env)
{
    env->game_s.health -= 20.0;

    if (env->game_s.health <= 0) {
        init_game_over(env);
    }
}

void fight_ennemies(env_t *env)
{
    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (!env->ennemies_s[i].is_valid)
            continue;
        if (check_collision_ennemies(env, i)) {
            send_fight_ennemies(env, i);
            return;
        }
    }
}

void fight_player(env_t *env)
{
    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (!env->ennemies_s[i].is_valid)
            continue;

        sfTime tmp_time = sfClock_getElapsedTime(env->ennemies_s[i].clock);
        float seconds = sfTime_asSeconds(tmp_time);

        if (seconds < 1.5)
            continue;

        sfClock_restart(env->ennemies_s[i].clock);
        if (check_collision_ennemies(env, i)) {
            send_fight_player(env);
        }
    }
}