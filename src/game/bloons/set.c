/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void set_type_bloons(env_t *env, int bloons_id, int type)
{
    sfColor new_color = get_color_type_bloons(type);

    env->bloons_s[bloons_id].type = type;
    sfSprite_setColor(env->bloons_s[bloons_id].sprite, (sfColor) new_color);
}

sfColor get_color_type_bloons(int type)
{
    sfColor new_color = {255, 255, 255, 255};

    if (type == BLOONS_RED)
        new_color = (sfColor) {233, 42, 42, 255};
    if (type == BLOONS_BLUE)
        new_color = (sfColor) {37, 126, 241, 255};
    if (type == BLOONS_PINK)
        new_color = (sfColor) {169, 96, 236, 255};
    if (type == BLOONS_GREEN)
        new_color = (sfColor) {76, 221, 27, 255};
    if (type == BLOONS_BLACK)
        new_color = (sfColor) {68, 68, 68, 255};
    return (new_color);
}