/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_game(env_t *env)
{
    init_map(env);
    generate_level_bloons(env, 30 * (env->game_s.level * 0.5));

    env->game_s.price[ALLIES_MONKEY] = "450$";
    env->game_s.price[ALLIES_BOOMRANG] = "120$";
    env->game_s.price[ALLIES_WIZARD] = "200$";

    env->game_s.special_mouse = -1;
    game_draw_init(env);
    game_draw_ui(env);
    game_draw_buttons(env);
    game_draw_mouse(env);
    draw_game_text(env);
    pause_draw(env);
    init_game_stats(env);
}

void init_game_stats(env_t *env)
{
    env->game_s.is_resume = false;
    env->game_s.is_gameover = false;
    set_level(env, 1);
    set_money(env, 250);
    env->game_s.health = 5;
    env->game_s.hit_bloons = 0;

    for (int i = 0; i < COUNT_TYPE_BLOONS; i++)
        env->game_s.bloons_needed[i] = 0;
}

void init_map(env_t *env)
{
    int i = 0;
    int fd = -1;
    char *str = NULL;

    if (!(env->game_s.map = malloc(sizeof(int *) * (MAX_POINTS_FILE + 1))))
        return;
    if ((fd = open(_GAME_MAP_1_FILE, O_RDONLY)) == -1) {
        my_putstr("Can't find the file map: ");
        my_putstr(_GAME_MAP_1_FILE);
        my_putchar('\n');
    }
    else {
        while ((str = get_next_line(fd)) != NULL) {
            if ((env->game_s.map[i] = malloc(sizeof(int) * 2)) == NULL)
                return;
            char **n_str = my_str_to_word_array(str);
            env->game_s.map[i][0] = my_getnbr(n_str[0]);
            env->game_s.map[i++][1] = my_getnbr(n_str[1]);
        }
        env->game_s.map[i] = NULL;
    }
}