/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_draw_inventory(env_t *env)
{
    env->game_s.t_inventory = sfTexture_createFromFile(GAME_INVENTORY, NULL);
    env->game_s.s_inventory = sfSprite_create();

    sfSprite_setTexture(env->game_s.s_inventory, env->game_s.t_inventory, sfTrue);
    sfSprite_setOrigin(env->game_s.s_inventory, (sfVector2f) {395 / 2, 269 / 2});
    sfSprite_setPosition(env->game_s.s_inventory, (sfVector2f) {1920 / 2, 1080 / 2});
}