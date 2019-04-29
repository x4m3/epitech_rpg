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

void draw_how_to_play(env_t *env)
{
    size_t i = 0;
    
    for(i = 0; i < MAX_LINE_HOW_TO; i++) {
        printf("%ld\n", i);
        env->menu_s.t_how_to[i] = sfText_create();
       printf("AAAAAAAA%ld\n", i);
        sfText_setString(env->menu_s.t_how_to[i], env->menu_s.s_how_to[i]);
        printf("ZZZZZZZZZZ%ld\n", i);
        sfText_setFont(env->menu_s.t_how_to[i], env->core_s.f_oetz);
        printf("EEEEEEEEEEEEE%ld\n", i);
        sfText_setColor(env->menu_s.t_how_to[i], (sfColor) {220, 220, 220, 255});
        printf("RRRRRRRRRRRRRRRR%ld\n", i);
        sfText_setOutlineColor(env->menu_s.t_how_to[i], (sfColor) {49, 100, 12, 255});
        printf("TTTTTTTTTTTTTTTTT%ld\n", i);
        sfText_setOutlineThickness(env->menu_s.t_how_to[i], 2.0);
        printf("IIIIIIIIIIIIIIIIIII%ld\n", i);
        sfText_setPosition(env->menu_s.t_how_to[i], (sfVector2f) {550, 310 + (i * 60)});
    }
    printf("%ld\n", i);
    env->menu_s.s_how_to[i] = NULL;
}

void draw_menu_howto(env_t *env)
{
    draw_box(env);
    draw_icons(env);
}