/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my_rpg.h"
#include "my.h"

static void draw_box(env_t *env)
{
    env->menu_s.t_box[0] = sfTexture_createFromFile(M_SETTINGS_BOX0, NULL);
    env->menu_s.t_box[1] = sfTexture_createFromFile(M_SETTINGS_BOX1, NULL);

    for (int i = 0; i < 2; i++) {
        env->menu_s.s_box[i] = sfSprite_create();
        sfSprite_setTexture(env->menu_s.s_box[i], env->menu_s.t_box[i], sfTrue);

        sfFloatRect bounds = sfSprite_getGlobalBounds(env->menu_s.s_box[i]);
        sfSprite_setOrigin(env->menu_s.s_box[i], (sfVector2f) {bounds.width / 2, bounds.height / 2});

        sfSprite_setScale(env->menu_s.s_box[i], (sfVector2f) {0.8, 0.8});
        sfSprite_setPosition(env->menu_s.s_box[i], (sfVector2f) {1920 / 2, 1080 / 2});
    }
}

static void draw_icons(env_t *env)
{
    env->menu_s.t_icon = sfTexture_createFromFile(M_HOWTO_ICON, NULL);

    env->menu_s.s_icon = sfSprite_create();
    sfSprite_setTexture(env->menu_s.s_icon, env->menu_s.t_icon, sfTrue);

    sfFloatRect bounds = sfSprite_getGlobalBounds(env->menu_s.s_icon);
    sfSprite_setOrigin(env->menu_s.s_icon, (sfVector2f) {bounds.width / 2, bounds.height / 2});

    sfSprite_setScale(env->menu_s.s_icon, (sfVector2f) {0.8, 0.8});
    sfSprite_setPosition(env->menu_s.s_icon, (sfVector2f) {1920/2, 1080/6});
}

void draw_menu_howto(env_t *env)
{
    draw_box(env);
    draw_icons(env);
}