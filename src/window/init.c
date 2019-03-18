/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void set_window(env_t *env)
{
    env->core_s.window = sfRenderWindow_create(env->core_s.mode,
    env->core_s.project_name, sfClose, NULL);

    sfRenderWindow_setFramerateLimit(env->core_s.window, env->core_s.framerate);

    init_sounds(env);
    init_menu(env);
    init_game(env);
}

void destroy(env_t *env)
{
    sfRenderWindow_destroy(env->core_s.window);
}