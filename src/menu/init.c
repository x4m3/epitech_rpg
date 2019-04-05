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
    create_button(env, (sfVector3f) {150, 150, 0.5}, BUTTON_HOWTO, "howto");
    create_button(env, (sfVector3f) {1800, 150, 0.5}, BUTTON_SETTINGS, "settings");
    create_button(env, (sfVector3f) {1900/2, 1050/2, 0.5}, BUTTON_PLAY, "play");
    sfTexture *t_logo = sfTexture_createFromFile("assets/game_ui/menu/logo.png", NULL);
    sfSprite *s_logo = sfSprite_create();
    sfSprite_setTexture(s_logo, t_logo, sfTrue);
    sfRenderWindow_drawSprite(env->core_s.window, s_logo, NULL);
    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
    menu_button_pressed(env);
}