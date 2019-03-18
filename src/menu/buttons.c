/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void check_buttons(env_t *env)
{
    int button_id = -1;
    sfVector2f vector = {1.05, 1.05};
    if ((button_id = is_over_button(env)) != -1) {
        if (env->menu_s.actual_status == M_STATUS_MAIN) {
            sfSprite_setScale(env->menu_s.s_button[button_id], vector);
            sfSprite_setScale(env->menu_s.s_icons[button_id], vector);
            sfText_setScale(env->menu_s.text_button[button_id], vector);
        }
        else {
            sfSprite_setScale(env->menu_s.s_set_icon[button_id], vector);
            sfSprite_setScale(env->menu_s.s_set_circle[button_id], vector);
        }
    }

    if (env->menu_s.actual_status == M_STATUS_MAIN)
        reset_effects(env, button_id);
    else
        reset_effects_settings(env, button_id);
}

void reset_effects(env_t *env, int exception)
{
    int count_buttons = sizeof(env->menu_s.s_button) / sizeof(sfSprite *);

    for (int i = 0; i < count_buttons; i++) {
        if (exception == i)
            continue;

        sfSprite_setScale(env->menu_s.s_button[i], (sfVector2f) {1.0, 1.0});
        sfSprite_setScale(env->menu_s.s_icons[i], (sfVector2f) {1.0, 1.0});
        sfText_setScale(env->menu_s.text_button[i], (sfVector2f) {1.0, 1.0});
    }
}

void reset_effects_settings(env_t *env, int exception)
{
    int count_buttons = sizeof(env->menu_s.s_set_icon) / sizeof(sfSprite *);

    for (int i = 0; i < count_buttons; i++) {
        if (exception == i)
            continue;

        sfSprite_setScale(env->menu_s.s_set_circle[i], (sfVector2f) {1.0, 1.0});
        sfSprite_setScale(env->menu_s.s_set_icon[i], (sfVector2f) {1.0, 1.0});
    }
}

int is_over_button(env_t *env)
{
    int count_buttons = 0;

    if (env->menu_s.actual_status == M_STATUS_MAIN)
        count_buttons = sizeof(env->menu_s.s_button) / sizeof(sfTexture *);
    else
        count_buttons = sizeof(env->menu_s.s_set_circle) / sizeof(sfTexture *);
    for (int i = 0; i < count_buttons; i++) {
        sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(env->core_s.window);
        sfFloatRect sprite_pos =
        sfSprite_getGlobalBounds(env->menu_s.s_set_circle[i]);

        if (env->menu_s.actual_status == M_STATUS_MAIN)
            sprite_pos = sfSprite_getGlobalBounds(env->menu_s.s_button[i]);
        else
            sprite_pos = sfSprite_getGlobalBounds(env->menu_s.s_set_circle[i]);
        if (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y))
            return (i);
    }
    return (-1);
}