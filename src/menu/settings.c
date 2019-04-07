/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my_rpg.h"
#include "my.h"

static void create_settings_buttons(env_t *env)
{
    if (get_sounds_music(env) >= 100.0)
        create_button(env, (sfVector3f) {1050, 450, 0.5}, BUTTON_ON, "music");
    else
        create_button(env, (sfVector3f) {1050, 450, 0.5}, BUTTON_OFF, "music");

    printf("sounds: %0.2f\n", get_sounds_effects(env));
    if (get_sounds_effects(env) >= 100.0)
        create_button(env, (sfVector3f) {1050, 500, 0.5}, BUTTON_ON, "sound");
    else
        create_button(env, (sfVector3f) {1050, 500, 0.5}, BUTTON_OFF, "sound");
}


void init_menu_settings(env_t *env)
{
    env->core_s.actual_status = STATUS_MENU;
    env->menu_s.actual_status = M_STATUS_SETTINGS;

    destroy_all_buttons(env);

    create_settings_buttons(env);
    create_button(env, (sfVector3f) {1250, 300, 0.5}, BUTTON_CLOSE, "close");

    init_menu_ui(env);
    draw_menu_settings(env);
}

void game_menu_draw_settings(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background, NULL);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[0], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[1], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_icon, NULL);
    sfRenderWindow_drawText(env->core_s.window, env->menu_s.txt_sets[0], NULL);
    sfRenderWindow_drawText(env->core_s.window, env->menu_s.txt_sets[1], NULL);

    display_buttons(env);

    sfRenderWindow_display(env->core_s.window);
}