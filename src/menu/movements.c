/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void menu_movements(env_t *env)
{
    sfTime time = sfClock_getElapsedTime(env->menu_s.clock);
    if (time.microseconds / 3000 > 1.0) {
        float rotation = sfSprite_getRotation(env->menu_s.s_background[0]);
        sfSprite_setRotation(env->menu_s.s_background[0], rotation + 0.4);

        for (int i = 0; i < 2; i++) {
            sfVector2f sky_pos = sfSprite_getPosition(env->menu_s.s_sky[i]);
            if (sky_pos.x > 1920 || sky_pos.y > 1080)
                sfSprite_setPosition(env->menu_s.s_sky[i],
                (sfVector2f) {-700.0, 0.0});
            else
                sfSprite_move(env->menu_s.s_sky[i], (sfVector2f) {2.0, 0.5});
        }

        sfClock_restart(env->menu_s.clock);
    }
}