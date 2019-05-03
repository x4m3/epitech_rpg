/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_game_over(env_t *env)
{
    destroy_all_buttons(env);
    env->game_s.actual_status = G_STATUS_LOST;
    sfVector3f pos = {
        1920 / 2,
        (1080 / 2) + 30,
        0.8
    };
    create_button(env, pos, BUTTON_PLAY, "settings");
    sfText_setString(env->game_s.txt_pause, "Game over");
    sfText_setPosition(env->game_s.txt_pause, (sfVector2f) {
        (1920 / 2) - 420, (1080 / 2) - 250
    });
}

void game_display_game_over(env_t *env)
{
    const sfView *view = sfRenderWindow_getDefaultView(env->core_s.window);
    sfRenderWindow_setView(env->core_s.window, view);

    sfRenderWindow_clear(env->core_s.window, sfBlack);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background,
    NULL);
    sfRenderWindow_drawText(env->core_s.window, env->game_s.txt_pause, NULL);

    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
}