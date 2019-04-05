/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_menu(env_t *env)
{
    env->core_s.actual_status = STATUS_MENU;
    env->menu_s.actual_status = M_STATUS_MAIN;

    destroy_all_buttons(env);

    create_button(env, (sfVector3f) {150, 150, 0.5}, BUTTON_HOWTO, "howto");
    create_button(env, (sfVector3f) {1800, 150, 0.5}, BUTTON_SETTINGS, "settings");
    create_button(env, (sfVector3f) {1900/2, 1050/2, 0.5}, BUTTON_PLAY, "play");

    init_menu_ui(env);
}

void game_menu_draw(env_t *env)
{
    printf("test\n");
    sfRenderWindow_clear(env->core_s.window, sfBlack);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_logo, NULL);
    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
}

void game_menu(env_t *env)
{
    game_menu_draw(env);
}