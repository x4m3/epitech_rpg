/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void game_play(env_t *env)
{
    game_play_draw(env);
    if (!env->game_s.is_resume && !env->game_s.is_gameover) {
        bloons_move(env);
        move_allies(env);
        check_game_buttons(env);
        check_hit(env);
        generate_bloons(env);
    }
    else {
        check_g_menu_buttons(env);
    }
}

void game_play_draw(env_t *env)
{
    sfRenderWindow_clear(env->core_s.window, (sfColor) {0, 208, 255, 255});

    sfRW_drawSprite(env->core_s.window, env->game_s.s_map[0], NULL);

    for (int i = 0; i < MAX_BLOONS; i++) if (env->bloons_s[i].is_valid)
        sfRW_drawSprite(env->core_s.window, env->bloons_s[i].sprite, NULL);
    for (int i = 0; i < MAX_ALLIES; i++) if (env->allies_s[i].is_valid) {
        sfRW_drawSprite(env->core_s.window, env->allies_s[i].sprite, NULL);
        draw_allies_circle(env, i);
    }

    game_play_draw_ui(env);
    sfRenderWindow_display(env->core_s.window);
}

void game_play_draw_ui(env_t *env)
{
    sfRW_drawSprite(env->core_s.window, env->game_s.s_ui, NULL);
    int count_text_price = sizeof(env->game_s.text_price) / sizeof(sfText *);
    for (int i = 0; i < count_text_price; i++)
        sfRW_drawText(env->core_s.window, env->game_s.text_price[i], NULL);

    sfRW_drawText(env->core_s.window, env->game_s.text_level, NULL);
    sfRW_drawText(env->core_s.window, env->game_s.text_money, NULL);
    int count_buttons = sizeof(env->game_s.s_button) / sizeof(sfSprite *);
    for (int i = 0; i < (int) count_buttons; i++)
        sfRW_drawSprite(env->core_s.window, env->game_s.s_button[i], NULL);

    if (env->game_s.special_mouse != -1) {
        sfRW_drawSprite(env->core_s.window, env->game_s.s_mouse, NULL);
        sfRW_drawCircle(env->core_s.window, env->game_s.s_mouse_circle, NULL);
    }
    if (env->game_s.is_resume)
        display_menu(env, "PAUSE");
    if (env->game_s.is_gameover)
        display_menu(env, "GAME OVER");
}

void draw_allies_circle(env_t *env, int allies_id)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(env->core_s.window);
    sfFloatRect sprite_pos =
    sfSprite_getGlobalBounds(env->allies_s[allies_id].sprite);

    if (env->game_s.special_mouse != -1
    || sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y))
        sfRW_drawCircle(env->core_s.window, env->allies_s[allies_id].circle,
        NULL);

}