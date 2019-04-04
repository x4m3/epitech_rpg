/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void menu_button_pressed(env_t *env)
{
    printf("%d\n", get_button_by_text(env, "howto"));
    printf("%d\n", get_button_by_text(env, "settings"));
    printf("%d\n", get_button_by_text(env, "play"));
}

void game_menu(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);
    char *button_howto = "assets/game_ui/btn/about.png";
    create_button(env, (sfVector2f) {150, 150}, button_howto, "howto");
    char *button_settings = "assets/game_ui/btn/settings.png";
    create_button(env, (sfVector2f) {1800, 150}, button_settings, "settings");
    char *button_play = "assets/game_ui/btn/play.png";
    create_button(env, (sfVector2f) {1900/2, 1050/2}, button_play, "play");
    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
    menu_button_pressed(env);
}