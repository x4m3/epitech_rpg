/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_menu_howto(env_t *env)
{
    env->core_s.actual_status = STATUS_MENU;
    env->menu_s.actual_status = M_STATUS_HOWTO;

    destroy_all_buttons(env);

    create_button(env, (sfVector3f) {1420, 170, 0.5}, BUTTON_CLOSE, "close");

    init_menu_ui(env);
    draw_menu_howto(env);
}

void game_menu_draw_howto(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background, NULL);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[0], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[1], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_icon, NULL);

    display_buttons(env);

    sfRenderWindow_display(env->core_s.window);
}