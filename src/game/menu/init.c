/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void display_menu(env_t *env, char *name)
{
    int count_buttons = sizeof(env->game_s.s_menu_circle) / sizeof(sfSprite *);

    sfText_setString(env->game_s.text, name);
    sfFloatRect bounds = sfText_getLocalBounds(env->game_s.text);
    sfText_setOrigin(env->game_s.text, (sfVector2f) {
        bounds.left + bounds.width/2, 0
    });

    sfRW_drawRectangle(env->core_s.window, env->game_s.background, NULL);
    sfRenderWindow_drawText(env->core_s.window, env->game_s.text, NULL);

    for (int i = 0; i < (int) count_buttons; i++) {
        sfRW_drawSprite(env->core_s.window, env->game_s.s_menu_circle[i],
        NULL);
        sfRW_drawSprite(env->core_s.window, env->game_s.s_menu_icons[i],
        NULL);
    }
}