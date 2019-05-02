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
        sfVector3f pos = {
            env->game_s.p_character.x,
            env->game_s.p_character.y,
            0.5
        };
        create_button(env, pos, BUTTON_SETTINGS, "settings");
        sfText_setString(env->game_s.txt_pause, "Resume");
        sfText_setPosition(env->game_s.txt_pause, (sfVector2f) {
            env->game_s.p_character.x - 270, env->game_s.p_character.y - 250
        });

    }
    else if (env->game_s.actual_status == G_STATUS_PAUSE) {
        env->game_s.actual_status = G_STATUS_PLAY;
        destroy_all_buttons(env);
    }
}
void game_display_pause(env_t *env)
{
    sfRenderWindow_drawText(env->core_s.window, env->game_s.txt_pause, NULL);
    display_buttons(env);
}