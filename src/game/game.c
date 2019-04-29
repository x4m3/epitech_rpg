/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static void game_display_map(env_t *env)
{
    for (int i = 0; env->game_s.s_map[i] != NULL; i++) {
        for (int j = 0; env->game_s.s_map[i][j] != NULL; j++) {
            sfRenderWindow_drawSprite(env->core_s.window, env->game_s.s_map[i][j], NULL);
        }
    }
}

static void game_display_character(env_t *env)
{
    sfSprite_setPosition(env->game_s.s_character, env->game_s.p_character);
    sfRenderWindow_drawSprite(env->core_s.window, env->game_s.s_character, NULL);
}

void init_game(env_t *env)
{
    env->core_s.actual_status = STATUS_PLAY;
    env->game_s.actual_status = G_STATUS_PLAY;

    env->game_s.inventory_open = false;

    init_textures_inventory();
    for (int i = 0; i < MAX_ITEMS_USER; i++)
        env->game_s.inventory[i] = -1;

    destroy_all_buttons(env);
    game_draw_view(env);
    game_draw_character(env);
    game_draw_inventory(env);
    init_message(env);
}

void game_play_draw(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);

    game_display_map(env);
    display_houses(env);
    display_ennemies(env);
    game_display_character(env);
    display_buttons(env);

    if (env->game_s.inventory_open)
        game_display_inventory(env);

    display_message(env);

    sfRenderWindow_setView(env->core_s.window, env->game_s.view);
    sfRenderWindow_display(env->core_s.window);
}