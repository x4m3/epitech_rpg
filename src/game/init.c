/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static const char *WELCOME_MESSAGE =
"Te voila prit au piege dans\n"\
"la ville de Wardo Shark.\n"\
"Des objets ont ete voles\n"\
"par des rebelles. Combat\n"\
"les pour ramener les\n"\
"objets.";

static void reset_var_game(env_t *env)
{
    env->core_s.actual_status = STATUS_PLAY;
    env->game_s.actual_status = G_STATUS_PLAY;

    env->game_s.inventory_open = false;
    env->game_s.health = 100.0;
    env->game_s.house_id = -1;
    env->game_s.count_house = 0;
    env->game_s.count_kill = 0;
    env->game_s.must_spawn = 0;
    for (int i = 0; i < MAX_ENNEMIES; i++) {
        if (env->ennemies_s[i].is_valid)
            delete_enemmies(env, i);
    }
    for (int i = 0; i < MAX_ITEMS_USER; i++)
        env->game_s.inventory[i] = -1;

    env->game_s.clock = sfClock_create();
}

static void player_movements(env_t *env)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        return char_movement_right(env);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        return char_movement_top(env);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        return char_movement_down(env);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        return char_movement_left(env);
}

void init_game(env_t *env)
{
    reset_var_game(env);
    init_textures_inventory();
    sfMusic_stop(env->core_s.m_music);
    sfMusic_play(env->core_s.m_game);
    destroy_all_buttons(env);
    game_draw_view(env);
    game_draw_character(env);
    game_draw_inventory(env);
    game_draw_quest(env);
    game_pause_draw(env);
    init_message(env);

    set_message(env, WELCOME_MESSAGE, 15);
}

void game_play(env_t *env)
{
    if (env->game_s.actual_status == G_STATUS_PLAY) {
        check_quest(env);
        fight_player(env);
        move_ennemies(env);
        game_play_draw(env);
        player_movements(env);
    }
    if (env->game_s.actual_status == G_STATUS_PAUSE) {
        game_display_pause(env);
    }
    if (env->game_s.actual_status == G_STATUS_LOST) {
        game_display_game_over(env);
    }
}