/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int create_button(env_t *env, sfVector2f pos, char *texture, char *text)
{
    int tmp = -1;
    if ((tmp = get_free_slot_buttons(env)) == -1)
        return (-1);

    env->buttons_s[tmp].is_valid = true;
    env->buttons_s[tmp].text = my_strdup(text);
    env->buttons_s[tmp].pos = pos;

    env->buttons_s[tmp].sprite = sfSprite_create();
    env->buttons_s[tmp].texture = sfTexture_createFromFile(texture, NULL);

    sfSprite_setTexture(env->buttons_s[tmp].sprite,
        env->buttons_s[tmp].texture, sfTrue);
    sfSprite_setPosition(env->buttons_s[tmp].sprite, env->buttons_s[tmp].pos);
    return (tmp);
}

void destroy_button(env_t *env, int button_id)
{
    if (env->buttons_s[button_id].is_valid)
        sfSprite_destroy(env->buttons_s[button_id].sprite);

    env->buttons_s[button_id].is_valid = false;
}