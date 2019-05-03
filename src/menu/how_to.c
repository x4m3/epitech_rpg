/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"


size_t read_from_file(env_t *env)
{
    int fd = open("data/how_to_play.txt", O_RDONLY);
    char *line = NULL;
    size_t i = 0;

    env->menu_s.s_how_to = malloc(sizeof(char *) * MAX_LINE_HOW_TO + 1);
    if (env->menu_s.s_how_to == NULL)
        return 1;
    if (fd == -1)
        return 1;
    while ((line = get_next_line(fd))) {
        if (!line)
            return 1;
        env->menu_s.s_how_to[i++] = my_strdup(line);
        free(line);
    }
    env->menu_s.s_how_to[i] = NULL;
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
    read_from_file(env);
    draw_menu_howto(env);
}

void game_menu_draw_howto(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, sfBlack);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_background,
    NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[0], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_box[1], NULL);
    sfRenderWindow_drawSprite(env->core_s.window, env->menu_s.s_icon, NULL);
    for (size_t i = 0;env->menu_s.s_how_to[i] != NULL; i++)
        sfRenderWindow_drawText(env->core_s.window, env->menu_s.t_how_to[i], 0);
    display_buttons(env);
    sfRenderWindow_display(env->core_s.window);
}
