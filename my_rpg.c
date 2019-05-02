/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static int check_args(int argc, char *argv[])
{
    if (argc < 2) {
        display_help(argv);
        return (84);
    }
    if (my_strcmp(argv[1], "--help") == 0 || my_strcmp(argv[1], "-h") == 0) {
        display_help(argv);
        return (84);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    env_t env;

    env.core_s.project_name = PROJECT_NAME;
    env.core_s.framerate = DEFAULT_FRAMERATE;
    env.core_s.mode = (sfVideoMode) {RESOLUTION_X, RESOLUTION_Y, BITS_PIXELS};
    int *seed = malloc(1);
    srand(*seed);
    reset_var(&env);
    if (check_args(argc, argv) == 84)
        return (84);
    if (open_map(&env, argc, argv) == 84)
        return (84);
    init_menu(&env);
    set_window(&env);
    game_state(&env);
    destroy(&env);
    return (0);
}