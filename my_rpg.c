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

static int set_srand(void)
{
    int *seed = malloc(1);
    if (seed == NULL)
        return (84);
    srand(*seed);
    return (0);
}

int main(int argc, char *argv[])
{
    env_t env;

    env.core_s.project_name = PROJECT_NAME;
    env.core_s.framerate = DEFAULT_FRAMERATE;
    env.core_s.mode = (sfVideoMode) {RESOLUTION_X, RESOLUTION_Y, BITS_PIXELS};
    if (set_srand() == 84)
        return (84);
    reset_var(&env);
    if (check_args(argc, argv) == 84)
        return (84);
    if (open_map(&env, argc, argv) == 84)
        return (send_error("Error: can't open the map.\n"));
    if (check_map(&env) == 84)
        return (send_error("Error: invalid map.\n"));
    init_menu(&env);
    if (set_window(&env) == 84)
        return (send_error("Error: you must have at least 10 fps.\n"));
    game_state(&env);
    destroy(&env);
    return (0);
}