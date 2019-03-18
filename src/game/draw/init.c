/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void game_draw_init(env_t *env)
{
    env->game_s.c_generate_bloons = sfClock_create();
    env->game_s.t_ui = sfTexture_createFromFile(_GAME_UI, NULL);
    env->game_s.t_characters = sfTexture_createFromFile(_GAME_CHAR, NULL);
    env->game_s.t_icons = sfTexture_createFromFile(_GAME_ICONS, NULL);
    env->game_s.t_map[0] = sfTexture_createFromFile(_GAME_MAP_1, NULL);
    env->game_s.t_buttons[0] = sfTexture_createFromFile(_GAME_BUTTONS, NULL);
    env->game_s.t_buttons[1] = sfTexture_createFromFile(_GAME_BUTTONS_2, NULL);
    env->game_s.text_level = sfText_create();
    env->game_s.text_money = sfText_create();
    env->game_s.background = sfRectangleShape_create();
    env->game_s.text = sfText_create();
    env->game_s.s_menu_circle[0] = sfSprite_create();
    env->game_s.s_menu_circle[1] = sfSprite_create();
    env->game_s.s_menu_icons[0] = sfSprite_create();
    env->game_s.s_menu_icons[1] = sfSprite_create();
}