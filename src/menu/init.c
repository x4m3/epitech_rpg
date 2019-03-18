/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void init_menu(env_t *env)
{
    env->menu_s.font = sfFont_createFromFile(_MENU_FONT);
    env->menu_s.clock = sfClock_create();

    init_menu_background(env);
    init_menu_icons(env);
    init_menu_settings(env);
    init_menu_buttons(env);
}

void game_menu(env_t *env)
{
    menu_movements(env);
    check_buttons(env);
    game_menu_draw(env);
}

void game_menu_draw(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, (sfColor) {0, 208, 255, 255});

    sfRW_drawSprite(env->core_s.window, env->menu_s.s_sky[0], NULL);
    sfRW_drawSprite(env->core_s.window, env->menu_s.s_sky[1], NULL);
    sfRW_drawSprite(env->core_s.window, env->menu_s.s_background[0], NULL);
    sfRW_drawSprite(env->core_s.window, env->menu_s.s_background[1], NULL);

    if (env->menu_s.actual_status == M_STATUS_MAIN)
        game_menu_draw_main(env);
    else if (env->menu_s.actual_status == M_STATUS_SETTINGS)
        game_menu_draw_settings(env);

    sfRenderWindow_display(env->core_s.window);
}

void game_menu_draw_main(env_t *env)
{
    int count_buttons = sizeof(env->menu_s.s_button) / sizeof(sfSprite *);
    for (int i = 0; i < (int) count_buttons; i++) {
        sfRW_drawSprite(env->core_s.window, env->menu_s.s_button[i], NULL);
        sfRW_drawSprite(env->core_s.window, env->menu_s.s_icons[i], NULL);
        sfRW_drawText(env->core_s.window, env->menu_s.text_button[i], NULL);
    }
}

void game_menu_draw_settings(env_t *env)
{
    if (env->core_s.sound_volume == 0)
        sfSprite_setColor(env->menu_s.s_set_icon[0], (sfColor) {0, 0, 0, 120});
    else
        sfSprite_setColor(env->menu_s.s_set_icon[0],
        (sfColor) {137, 233, 12, 255});

    if (sfMusic_getVolume(env->core_s.m_click) <= 0.0)
        sfSprite_setColor(env->menu_s.s_set_icon[1], (sfColor) {0, 0, 0, 120});
    else
        sfSprite_setColor(env->menu_s.s_set_icon[1],
        (sfColor) {253, 183, 0, 255});

    int count_buttons = sizeof(env->menu_s.s_set_icon) / sizeof(sfSprite *);
    for (int i = 0; i < (int) count_buttons; i++) {
        sfRW_drawSprite(env->core_s.window, env->menu_s.s_set_circle[i], NULL);
        sfRW_drawSprite(env->core_s.window, env->menu_s.s_set_icon[i], NULL);
    }
}