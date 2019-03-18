/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void menu_events(env_t *env)
{
    int button_id = -1;
    if (env->core_s.event.type == sfEvtMouseButtonPressed) {
        if ((button_id = is_over_button(env)) != -1)
            on_button_hitted(env, button_id, env->menu_s.actual_status);
    }
}

void on_button_hitted(env_t *env, int button_id, int actual_status)
{
    if (actual_status == M_STATUS_MAIN && button_id == 0)
        env->core_s.actual_status = STATUS_PLAY;

    if (actual_status == M_STATUS_MAIN && button_id == 1)
        sfRenderWindow_close(env->core_s.window);

    if (actual_status == M_STATUS_MAIN && button_id == 2)
        env->menu_s.actual_status = M_STATUS_SETTINGS;

    if (actual_status == M_STATUS_SETTINGS && button_id == 0)
        env->core_s.sound_volume = (env->core_s.sound_volume != 0 ? 0 : 100);

    if (actual_status == M_STATUS_SETTINGS && button_id == 1)
        set_sound_effects(env);

    if (actual_status == M_STATUS_SETTINGS && button_id == 2)
        env->menu_s.actual_status = M_STATUS_MAIN;

    sfMusic_play(env->core_s.m_click);
}