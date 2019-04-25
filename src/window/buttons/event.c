/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void check_buttons_click(env_t *env)
{
    int button_id = -1;

    if (env->core_s.event.type == sfEvtMouseButtonPressed) {
        if ((button_id = is_over_button(env)) != -1)
            on_button_hitted(env, button_id);
    }
}

void on_button_hitted(env_t *env, int button_id)
{
    if (env->core_s.actual_status == STATUS_MENU)
        on_menu_button_hitted(env, button_id);
    printf("button_id: %d is hitted\n", button_id);
    sfMusic_stop(env->core_s.m_effects[0]);
    sfMusic_play(env->core_s.m_effects[0]);
    printf("playing sound\n");
}

int is_over_button(env_t *env)
{
    for (int i = 0; i < MAX_BUTTONS; i++) if (env->buttons_s[i].is_valid) {
        sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(env->core_s.window);
        sfFloatRect sprite_pos =
        sfSprite_getGlobalBounds(env->buttons_s[i].sprite);

        if (sfFloatRect_contains(&sprite_pos, mouse_pos.x, mouse_pos.y))
            return (i);
    }
    return (-1);
}
int get_button_by_text(env_t *env, char *text)
{
    for (int i = 0; i < MAX_BUTTONS; i++) if (env->buttons_s[i].is_valid) {
        if (my_strcmp(text, env->buttons_s[i].text) == 0)
            return (i);
    }
    return (-1);
}

int get_free_slot_buttons(env_t *env)
{
    for (int i = 0; i < MAX_BUTTONS; i++) {
        if (!env->buttons_s[i].is_valid)
            return (i);
    }
    return (-1);
}