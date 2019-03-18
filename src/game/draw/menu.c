/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void pause_draw(env_t *env)
{
    pause_draw_text(env);
    pause_draw_background(env);
    pause_draw_circle(env);
    pause_draw_icons(env);
}

void pause_draw_text(env_t *env)
{
    sfText_setFont(env->game_s.text, env->menu_s.font);
    sfText_setCharacterSize(env->game_s.text, 150);
    sfText_setColor(env->game_s.text, (sfColor) {245, 189, 0, 255});
    sfText_setOutlineColor(env->game_s.text, (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(env->game_s.text, 2.0);
    sfText_setString(env->game_s.text, "PAUSE");
    sfText_setPosition(env->game_s.text, (sfVector2f) {960.0, 250.0});
}

void pause_draw_background(env_t *env)
{
    sfRectangleShape_setSize(env->game_s.background, (sfVector2f) {
        1920, 1080
    });

    sfRectangleShape_setFillColor(env->game_s.background, (sfColor) {
        123, 123, 123, 150
    });
}

void pause_draw_circle(env_t *env)
{
    sfSprite_setTexture(env->game_s.s_menu_circle[0], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->game_s.s_menu_circle[0],
    (sfIntRect) {151, 742, 126, 132});
    sfSprite_setPosition(env->game_s.s_menu_circle[0],
    (sfVector2f) {790.0, 485.0});

    sfSprite_setTexture(env->game_s.s_menu_circle[1], env->menu_s.t_icons[1],
    sfTrue);
    sfSprite_setTextureRect(env->game_s.s_menu_circle[1],
    (sfIntRect) {151, 742, 126, 132});
    sfSprite_setPosition(env->game_s.s_menu_circle[1],
    (sfVector2f) {955.0, 485.0});
}

void pause_draw_icons(env_t *env)
{
    sfSprite_setTexture(env->game_s.s_menu_icons[0], env->menu_s.t_icons[0],
    sfTrue);
    sfSprite_setTextureRect(env->game_s.s_menu_icons[0],
    (sfIntRect) {1492, 1615, 56, 59});
    sfSprite_setPosition(env->game_s.s_menu_icons[0],
    (sfVector2f) {825.0, 520.0});

    sfSprite_setTexture(env->game_s.s_menu_icons[1], env->menu_s.t_icons[0],
    sfTrue);
    sfSprite_setTextureRect(env->game_s.s_menu_icons[1],
    (sfIntRect) {1288, 1666, 50, 50});
    sfSprite_setPosition(env->game_s.s_menu_icons[1],
    (sfVector2f) {995.0, 525.0});
}