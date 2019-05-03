/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static int map_strlen(env_t *env, int index)
{
    int i = 0;
    for (i = 0; env->game_s.s_map[index][i] != NULL; i++);
    return (i);
}

int check_map(env_t *env)
{
    int count = -1;
    size_t i = 0;
    for (i = 0; env->game_s.s_map[i] != NULL; i++) {
        if (count != -1 && count != map_strlen(env, i)) {
            return (84);
        }
        count = map_strlen(env, i);
    }
    if (i < 14)
        return (84);
    return (0);
}
