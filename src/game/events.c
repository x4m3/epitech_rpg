/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_events(env_t *env)
{
    if (env->core_s.event.type == sfEvtKeyPressed) {
        if (env->core_s.event.key.code == sfKeyEscape)
            init_pause(env);
        if (env->core_s.event.key.code == sfKeyP)
            init_game_over(env);
        if (env->game_s.actual_status != G_STATUS_PLAY)
            return;
        if (env->core_s.event.key.code == sfKeyDown)
            char_movement_down(env);
        if (env->core_s.event.key.code == sfKeyUp)
            char_movement_top(env);
        if (env->core_s.event.key.code == sfKeyLeft)
            char_movement_left(env);
        if (env->core_s.event.key.code == sfKeyRight)
            char_movement_right(env);
        if (env->core_s.event.key.code == sfKeySpace)
            fight_ennemies(env);
        if (env->core_s.event.key.code == sfKeyI)
            env->game_s.inventory_open =
            (env->game_s.inventory_open ? false : true);
    }
}

void on_game_button_hitted(env_t *env, int button_id)
{
    if (get_button_by_text(env, "settings") == button_id) {
        const sfView *view = sfRenderWindow_getDefaultView(env->core_s.window);
        sfRenderWindow_setView(env->core_s.window, view);
        init_menu(env);
    }
    if (get_button_by_text(env, "play") == button_id) {
        init_pause(env);
    }
}