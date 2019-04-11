/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int open_map(env_t *env, int argc, char *argv[])
{
    (void) argc;
    int fd = -1;
    char *str = NULL;
    int tmp = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        send_error("Can't open the file.\n");
        return (84);
    }

    env->game_s.t_map = sfTexture_createFromFile("assets/test.png", NULL);

    if (!(env->game_s.map = malloc(sizeof(char *) * (MAP_MAX_LINES + 1))))
        return (84);
    if (!(env->game_s.s_map = malloc(sizeof(sfSprite *) * (MAP_MAX_LINES + 1))))
        return (84);

    while ((str = get_next_line(fd))) {
        printf("[%d] -> malloc size %d\n", tmp, (my_strlen(str) + 1));
        printf("[%d] %s\n", tmp, str);
        if (!(env->game_s.s_map[tmp] = malloc(sizeof(sfSprite *) * (my_strlen(str) + 1))))
            return (84);
        env->game_s.map[tmp] = my_strdup(str);
        create_sprites_map(env, tmp);
        tmp++;
        free(str);
    }
    env->game_s.map[tmp] = NULL;
    return (0);
}

void create_sprites_map(env_t *env, int index)
{
    printf("[%d] strlen: %d\n", index, my_strlen(env->game_s.map[index]));
    for (int i = 0; env->game_s.map[index][i] != '\0'; i++) {
        printf("[%d][%d]: sprite created\n", index, i);

        env->game_s.s_map[index][i] = sfSprite_create();
        sfSprite_setTexture(env->game_s.s_map[index][i], env->game_s.t_map, sfTrue);
        sfSprite_setPosition(env->game_s.s_map[index][i], (sfVector2f) {i * 33, index * 33});
    }
}