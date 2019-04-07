/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my_rpg.h"
#include "my.h"

void create_setting_button(env_t *env)
{
    char *texture = "assets/game_ui/settings/96.png";

    create_button(env, (sfVector3f) {960, 450, 0.5}, texture, "Music");
    create_button(env, (sfVector3f) {960, 500, 0.5}, texture, "Sound");
}

void display_setting_menu(env_t *env)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;

    texture = sfTexture_createFromFile("assets/game_ui/settings/bg.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f) {600, 300});
    sfSprite_setScale(sprite, (sfVector2f) {0.5, 0.5});
    create_setting_button(env);
    sfRenderWindow_drawSprite(env->core_s.window, sprite, NULL);
}