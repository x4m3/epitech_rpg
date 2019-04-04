/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void check_buttons(env_t *env)
{
    int button_id = -1;
    sfVector2f vector = {1.05, 1.05};

    if ((button_id = is_over_button(env)) != -1) {
        sfSprite_setScale(env->buttons_s[button_id].sprite, vector);
    }
    reset_effects(env, button_id);
}

void reset_effects(env_t *env, int exception)
{
    for (int i = 0; i < MAX_BUTTONS; i++) if (env->buttons_s[i].is_valid) {
        if (exception == i)
            continue;

        sfSprite_setScale(env->buttons_s[i].sprite, (sfVector2f) {1.0, 1.0});
    }
}