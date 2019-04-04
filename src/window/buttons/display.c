/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void display_buttons(env_t *env)
{
    for (int i = 0; i < MAX_BUTTONS; i++) if (env->buttons_s[i].is_valid) {
        sfRenderWindow_drawSprite(env->core_s.window, env->buttons_s[i].sprite, NULL);
    }
}