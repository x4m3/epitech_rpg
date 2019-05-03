/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_pause(env_t *env)
{
    destroy_all_buttons(env);
    if (env->game_s.actual_status == G_STATUS_PLAY) {
        env->game_s.actual_status = G_STATUS_PAUSE;
        sfVector3f pos = {(1920 / 2) - 100, (1080 / 2) + 30, 0.8};
        create_button(env, pos, BUTTON_PLAY, "play");
        pos = (sfVector3f) {(1920 / 2) + 100, (1080 / 2) + 30, 0.8};
        create_button(env, pos, BUTTON_EXIT, "settings");
        sfText_setString(env->game_s.txt_pause, "Resume");
        sfText_setPosition(env->game_s.txt_pause, (sfVector2f) {
            (1920 / 2) - 270, (1080 / 2) - 250});
        const sfView *view = sfRenderWindow_getDefaultView(env->core_s.window);
        sfRenderWindow_setView(env->core_s.window, view);
    }
    else if (env->game_s.actual_status == G_STATUS_PAUSE) {
        env->game_s.actual_status = G_STATUS_PLAY;
        destroy_all_buttons(env);
    }
}

void game_display_pause(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background,
    NULL);
    sfRenderWindow_drawText(env->core_s.window, env->game_s.txt_pause, NULL);

    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
}