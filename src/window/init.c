/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void set_window(env_t *env)
{
    env->core_s.window = sfRenderWindow_create(env->core_s.mode,
    env->core_s.project_name, sfClose, NULL);

    sfRenderWindow_setFramerateLimit(env->core_s.window, env->core_s.framerate);

    init_fonts(env);
    init_sounds(env);
    init_menu(env);
}

void destroy(env_t *env)
{
    sfRenderWindow_destroy(env->core_s.window);
}

void reset_var(env_t *env)
{
    env->game_s.map_size.width = 0;
    env->game_s.map_size.height = 0;

    for (int i = 0; i < MAX_BUTTONS; i++) {
        env->buttons_s[i].is_valid = false;
        destroy_button(env, i);
    }

    for (int i = 0; i < MAX_HOUSES; i++) {
        env->houses_s[i].is_valid = false;
    }
}