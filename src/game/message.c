/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_message(env_t *env)
{
    env->game_s.tmp_message = NULL;


    env->game_s.txt_message = sfText_create();
    env->game_s.t_message = sfTexture_createFromFile(GAME_MESSAGE, NULL);
    env->game_s.s_message = sfSprite_create();

    sfSprite_setTexture(env->game_s.s_message, env->game_s.t_message, sfTrue);
    sfSprite_setScale(env->game_s.s_message, (sfVector2f) {0.3, 0.3});

    sfText_setCharacterSize(env->game_s.txt_message, 12);
    sfText_setFont(env->game_s.txt_message, env->core_s.f_oetz);
    sfText_setColor(env->game_s.txt_message, (sfColor) {220, 220, 220, 255});
    sfText_setOutlineColor(env->game_s.txt_message, (sfColor) {0, 0, 0, 255});
    sfText_setOutlineThickness(env->game_s.txt_message, 2.0);

}

void set_message(env_t *env, char *text)
{
    if (!env->game_s.tmp_message)
        free(env->game_s.tmp_message);
    env->game_s.tmp_message = my_strdup(text);
}

void display_message(env_t *env)
{
    if (env->game_s.tmp_message == NULL)
        return;

    sfVector2f pos = sfView_getCenter(env->game_s.view);
    pos.x -= 200;
    pos.y -= 180;
    sfSprite_setPosition(env->game_s.s_message, pos);
    sfText_setPosition(env->game_s.txt_message, (sfVector2f) {pos.x + 15, pos.y + 10});
    sfText_setString(env->game_s.txt_message, env->game_s.tmp_message);
    sfRenderWindow_drawSprite(env->core_s.window, env->game_s.s_message, NULL);
    sfRenderWindow_drawText(env->core_s.window, env->game_s.txt_message, NULL);

    env->game_s.tmp_message = NULL;
}