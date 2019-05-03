/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static void get_size_map(env_t *env, char *str)
{
    if ((int)env->game_s.map_size.width < my_strlen(str) * 64)
        env->game_s.map_size.width = my_strlen(str) * 64;
}

static int create_sprites_map(env_t *env, char *str, int index)
{
    int i = 0;

    if (!(env->game_s.s_map[index] = malloc(sizeof(sfSprite *) *
    (my_strlen(str) + 1))))
        return (84);
    get_size_map(env, str);
    for (i = 0; str[i]; i++) {
        env->game_s.s_map[index][i] = sfSprite_create();
        sfSprite_setTexture(env->game_s.s_map[index][i], env->game_s.t_map,
        sfTrue);
        sfSprite_setTextureRect(env->game_s.s_map[index][i],
        get_texture_map(str[i]));
        sfSprite_setPosition(env->game_s.s_map[index][i],
        (sfVector2f) {i * 64, index * 64});
    }
    env->game_s.s_map[index][i] = NULL;
    env->game_s.s_map[index + 1] = NULL;
    env->game_s.map_size.height = (index + 1) * 64;
    return (0);
}

static void create_house_map(env_t *env, char *str, int index)
{
    (void) index;
    char **data = my_str_to_word_array(str);
    houses_t tmp_house;

    tmp_house.pos.x = (float) my_getnbr(data[0]);
    tmp_house.pos.y = (float) my_getnbr(data[1]);

    create_house(env, tmp_house);
}

static void init_open_map(env_t *env, int fd)
{
    char *str = NULL;
    int tmp = 0;
    int status = 0;

    while ((str = get_next_line(fd))) {
        if (str[0] == '#') {
            status++;
            tmp = 0;
            continue;
        }
        if (status == 1)
            create_sprites_map(env, str, tmp);
        if (status == 2)
            create_house_map(env, str, tmp);
        tmp++;
        free(str);
    }
}

int open_map(env_t *env, int argc, char *argv[])
{
    (void) argc;
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        send_error("Can't open the file.\n");
        return (84);
    }
    env->game_s.t_map = sfTexture_createFromFile(GAME_ASSETS_MAP, NULL);
    if (!(env->game_s.s_map = malloc(sizeof(sfSprite *)
    * (MAP_MAX_LINES + 1))))
        return (84);
    init_open_map(env, fd);
    return (0);
}