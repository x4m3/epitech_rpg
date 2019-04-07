/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void on_menu_button_hitted(env_t *env, int button_id)
{
    if (get_button_by_text(env, "settings") == button_id)
        return init_menu_settings(env);
    if (get_button_by_text(env, "howto") == button_id) {
        env->menu_s.actual_status = M_STATUS_HOWTO;
        return;
    }
    if (get_button_by_text(env, "play") == button_id) {
        env->core_s.actual_status = STATUS_PLAY;
        return;
    }
    if (get_button_by_text(env, "close") == button_id)
        return init_menu(env);
    if (get_button_by_text(env, "music") == button_id) {
        set_sounds_music(env);
        return init_menu_settings(env);
    }
    if (get_button_by_text(env, "sound") == button_id) {
        set_sounds_effects(env);
        return init_menu_settings(env);
    }
    if (get_button_by_text(env, "exit") == button_id)
        return sfRenderWindow_close(env->core_s.window);
}