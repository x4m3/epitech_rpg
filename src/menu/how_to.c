/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

static void draw_how_to_play(env_t *env, char *line, double i)
{
    sfText *how_to_play = sfText_create();

    sfText_setString(how_to_play, line);
    sfText_setFont(how_to_play, env->core_s.f_oetz);
    sfText_setColor(how_to_play, (sfColor) {220, 220, 220, 255});
    sfText_setOutlineColor(how_to_play, (sfColor) {49, 100, 12, 255});
    sfText_setOutlineThickness(how_to_play, 2.0);
    sfText_setPosition(how_to_play, (sfVector2f) {550, 300 + i});
    sfRenderWindow_drawText(env->core_s.window, how_to_play, NULL);
}

size_t read_from_file(env_t *env)
{
    int fd = open("data/how_to_play.txt", O_RDONLY);
    char *line;
    double i = 0;

    if (fd == -1)
        return 1;
    while ((line = get_next_line(fd))) {
        if (!line)
            return 1;
        draw_how_to_play(env, line, i);
        free(line);
        i += 60;
    }
    close(fd);
    return 0;
}

void init_menu_howto(env_t *env)
{
    env->core_s.actual_status = STATUS_MENU;
    env->menu_s.actual_status = M_STATUS_HOWTO;

    destroy_all_buttons(env);

    create_button(env, (sfVector3f) {1420, 170, 0.5}, BUTTON_CLOSE, "close");

    init_menu_ui(env);
    draw_menu_howto(env);
    if (read_from_file(env))
        return;
}

void game_menu_draw_howto(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background,
    NULL);

    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[0], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[1], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_icon, NULL);
    read_from_file(env);
    display_buttons(env);

    sfRenderWindow_display(env->core_s.window);
}
