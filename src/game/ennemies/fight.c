/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static char* MESSAGE_WIN =
"Felicitation, tu as enfin\n\
trouve ta clef.\n\n\
Elle a ete ajoutee a ton\n\
inventaire.";

static char* MESSAGE_END =
"FELICITATION!\n\n\
Tu as gagne trouve toutes\n\
les clefs.";

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
            add_item_user(env, "Key");
            set_message(env, MESSAGE_WIN, 8);
            env->game_s.house_id++;
        }
        if (env->game_s.house_id > get_max_house(env))
            set_message(env, MESSAGE_END, 5);
    }

}

void fight_ennemies(env_t *env)
{
    for (int i = 0; i < MAX_ENNEMIES; i++) if (env->ennemies_s[i].is_valid) {
        if (check_collision_ennemies(env, i))
            return send_fight_ennemies(env, i);
    }
}