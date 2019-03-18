/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void game_events(env_t *env)
{
    int button_id = -1;
    if (env->core_s.event.type == sfEvtMouseButtonPressed &&
    (!env->game_s.is_resume && !env->game_s.is_gameover)) {
        if ((button_id = is_over_game_button(env)) != -1)
            on_game_button_hitted(env, button_id);
        else if (env->game_s.special_mouse != -1)
            on_game_allies_drop(env);
    }

    if (env->core_s.event.type == sfEvtMouseButtonPressed &&
    (env->game_s.is_resume || env->game_s.is_gameover) &&
    (button_id = is_over_g_menu_button(env)) != -1) {
        on_g_menu_button_hitted(env, button_id);
    }

    if (sfKeyboard_isKeyPressed(sfKeyEscape) && !env->game_s.is_gameover) {
        env->game_s.is_resume = (env->game_s.is_resume ? false : true);
    }
}

void on_game_button_hitted(env_t *env, int button_id)
{
    if (env->game_s.special_mouse == -1) {
        int price = my_getnbr(env->game_s.price[button_id]);
        if (get_money(env) >= price) {
            env->game_s.special_mouse = button_id;
            sfSprite_setTextureRect(env->game_s.s_mouse,
            (sfIntRect) {92 * button_id, 0, 92, 92});
            sfMusic_play(env->core_s.m_click);
        }
        else {
            sfMusic_play(env->core_s.m_error);
        }
    }
    else {
        env->game_s.special_mouse = -1;
    }
}

void on_g_menu_button_hitted(env_t *env, int button_id)
{
    if (button_id == 0) {
        init_game_stats(env);
        for (int i = 0; i < MAX_ALLIES; i++) if (env->allies_s[i].is_valid) {
            delete_allies(env, i);
        }
        for (int i = 0; i < MAX_BLOONS; i++) if (env->bloons_s[i].is_valid) {
            delete_bloons(env, i);
        }
        env->core_s.actual_status = STATUS_MENU;
    }
    if (button_id == 1)
        sfRenderWindow_close(env->core_s.window);
}

void on_game_allies_drop(env_t *env)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(env->core_s.window);
    int price = my_getnbr(env->game_s.price[env->game_s.special_mouse]);
    set_money(env, env->game_s.money - price);
    create_allies(env, env->game_s.special_mouse, (sfVector2f) {
        mouse_pos.x,
        mouse_pos.y
    });

    env->game_s.special_mouse = -1;
}