/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static sfIntRect get_texture_map(char texture)
{
    switch (texture) {
    case '1':
        return ((sfIntRect) {148, 462, 64, 64});
    case '2':
        return ((sfIntRect) {214, 462, 64, 64});
    case '3':
        return ((sfIntRect) {280, 462, 64, 64});
    case '4':
        return ((sfIntRect) {610, 0, 64, 64});
    case '5':
        return ((sfIntRect) {676, 0, 64, 64});
    case '6':
        return ((sfIntRect) {742, 0, 64, 64});
    case '7':
        return ((sfIntRect) {610, 66, 64, 64});
    case '8':
        return ((sfIntRect) {676, 66, 64, 64});
    case '9':
        return ((sfIntRect) {742, 66, 64, 64});
    case 'A':
        return ((sfIntRect) {610, 132, 64, 64});
    case 'B':
        return ((sfIntRect) {676, 132, 64, 64});
    case 'C':
        return ((sfIntRect) {742, 132, 64, 64});
    case 'D':
        return ((sfIntRect) {148, 330, 64, 64});
    case 'E':
        return ((sfIntRect) {148, 396, 64, 64});
    case 'F':
        return ((sfIntRect) {214, 396, 64, 64});
    case 'G':
        return ((sfIntRect) {280, 396, 64, 64});
    case 'H':
        return ((sfIntRect) {280, 330, 64, 64});
    }

    return ((sfIntRect) {214, 66, 64, 64});
}

static void get_size_map(env_t *env, char *str)
{
    if ((int)env->game_s.map_size.width < my_strlen(str) * 64)
        env->game_s.map_size.width = my_strlen(str) * 64;
}

static int create_sprites_map(env_t *env, char *str, int index)
{
    int i = 0;

    if (!(env->game_s.s_map[index] = malloc(sizeof(sfSprite *) * (my_strlen(str) + 1))))
        return (84);
    get_size_map(env, str);
    for (i = 0; str[i]; i++) {
        env->game_s.s_map[index][i] = sfSprite_create();
        sfSprite_setTexture(env->game_s.s_map[index][i], env->game_s.t_map, sfTrue);
        sfSprite_setTextureRect(env->game_s.s_map[index][i], get_texture_map(str[i]));
        sfSprite_setPosition(env->game_s.s_map[index][i], (sfVector2f) {i * 64, index * 64});
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

int open_map(env_t *env, int argc, char *argv[])
{
    (void) argc;
    int fd = -1;
    char *str = NULL;
    int tmp = 0;
    int status = 0;

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        send_error("Can't open the file.\n");
        return (84);
    }
    env->game_s.t_map = sfTexture_createFromFile(GAME_ASSETS_MAP, NULL);
    if (!(env->game_s.s_map = malloc(sizeof(sfSprite *) * (MAP_MAX_LINES + 1))))
        return (84);
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
    return (0);
}