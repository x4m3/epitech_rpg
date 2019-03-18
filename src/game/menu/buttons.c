/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void check_g_menu_buttons(env_t *env)
{
    int button_id = -1;
    if ((button_id = is_over_g_menu_button(env)) != -1) {
        sfSprite_setScale(env->game_s.s_menu_circle[button_id], (sfVector2f) {
            1.05, 1.05
        });
        sfSprite_setScale(env->game_s.s_menu_icons[button_id], (sfVector2f) {
            1.05, 1.05
        });
    }
    reset_btn_g_menu_effects(env, button_id);
    refresh_special_mouse(env);
}

void reset_btn_g_menu_effects(env_t *env, int exception)
{
    int count_buttons = sizeof(env->game_s.s_menu_circle) / sizeof(sfSprite *);

    for (int i = 0; i < count_buttons; i++) {
        if (exception == i)
            continue;

        sfSprite_setScale(env->game_s.s_menu_circle[i], (sfVector2f) {
            1.0, 1.0
        });
        sfSprite_setScale(env->game_s.s_menu_icons[i], (sfVector2f) {
            1.0, 1.0
        });
    }
}

int is_over_g_menu_button(env_t *env)
{
    sfVector2i mouse_pos;
    sfFloatRect sprite_pos;
    int count_buttons = sizeof(env->game_s.s_menu_circle) / sizeof(sfSprite *);
    for (int i = 0; i < count_buttons; i++) {
        mouse_pos = sfMouse_getPositionRW(env->core_s.window);
        sprite_pos = sfSprite_getGlobalBounds(env->game_s.s_menu_circle[i]);

        if (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y))
            return (i);
    }
    return (-1);
}