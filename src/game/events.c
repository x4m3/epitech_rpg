/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void game_events(env_t *env)
{
    if (env->core_s.event.type == sfEvtKeyPressed) {
        sfVector2f pos = sfView_getCenter(env->game_s.view);
        printf("MAPSIZE (%d, %d)\n", env->game_s.map_size.width, env->game_s.map_size.height);
        printf("(%0.2f, %0.2f) | (%0.2f, %0.2f)\n", pos.x, pos.y, env->game_s.p_character.x, env->game_s.p_character.y);
        if (env->core_s.event.key.code == sfKeyDown) {
            my_putstr("Key down\n");
            printf("if (%0.0f <= %d) == true\n", pos.y - (1080 / 2) - 34, (env->game_s.map_size.height - (1080 / 2)) / 2);

            if (pos.y - (1080 / 2) + 20 <= (env->game_s.map_size.height - (1080 / 2)) / 2) {
                sfView_move(env->game_s.view, (sfVector2f) {0, 4});
            }

            set_character_rotation(env, ROTATION_DOWN);
            set_character_animation(env);
            env->game_s.p_character.y += 4;
        }
        if (env->core_s.event.key.code == sfKeyUp) {
            my_putstr("Key up\n");
            if (pos.y > 320)
                sfView_move(env->game_s.view, (sfVector2f) {0, -4});
            set_character_rotation(env, ROTATION_UP);
            set_character_animation(env);
            env->game_s.p_character.y -= 4;
        }
        if (env->core_s.event.key.code == sfKeyLeft) {
            my_putstr("Key left\n");
            if (pos.x > 1920 / 4)
                sfView_move(env->game_s.view, (sfVector2f) {-4, 0});
            set_character_rotation(env, ROTATION_LEFT);
            set_character_animation(env);
            env->game_s.p_character.x -= 4;
        }
        if (env->core_s.event.key.code == sfKeyRight) {
            my_putstr("Key right\n");
            sfView_move(env->game_s.view, (sfVector2f) {4, 0});
            set_character_rotation(env, ROTATION_RIGHT);
            set_character_animation(env);
            env->game_s.p_character.x += 4;
        }
    }
}