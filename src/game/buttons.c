/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void check_game_buttons(env_t *env)
{
    int button_id = -1;
    if ((button_id = is_over_game_button(env)) != -1) {
            sfSprite_setScale(env->game_s.s_button[button_id], (sfVector2f) {
                1.05, 1.05
            });
    }
    reset_btn_game_effects(env, button_id);
    refresh_special_mouse(env);
}

void reset_btn_game_effects(env_t *env, int exception)
{
    int count_buttons = sizeof(env->game_s.s_button) / sizeof(sfSprite *);

    for (int i = 0; i < count_buttons; i++) {
        if (exception == i)
            continue;

        sfSprite_setScale(env->game_s.s_button[i], (sfVector2f) {1.0, 1.0});
    }
}

int is_over_game_button(env_t *env)
{
    sfVector2i mouse_pos;
    sfFloatRect sprite_pos;
    int count_buttons = sizeof(env->game_s.s_button) / sizeof(sfSprite *);
    for (int i = 0; i < count_buttons; i++) {
        mouse_pos = sfMouse_getPositionRW(env->core_s.window);
        sprite_pos = sfSprite_getGlobalBounds(env->game_s.s_button[i]);

        if (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y))
            return (i);
    }
    return (-1);
}

void refresh_special_mouse(env_t *env)
{
    if (env->game_s.special_mouse != -1) {
        sfVector2i mouse_pos = sfMouse_getPositionRW(env->core_s.window);
        sfRenderWindow_setMouseCursorVisible(env->core_s.window, sfFalse);
        sfSprite_setPosition(env->game_s.s_mouse, (sfVector2f) {
            (float) mouse_pos.x,
            (float) mouse_pos.y
        });
        sfCircleShape_setPosition(env->game_s.s_mouse_circle, (sfVector2f) {
            (float) mouse_pos.x,
            (float) mouse_pos.y
        });
    }
    else {
        sfRenderWindow_setMouseCursorVisible(env->core_s.window, sfTrue);
    }
}