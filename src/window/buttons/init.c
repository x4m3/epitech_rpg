/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

int create_button(env_t *env, sfVector3f pos, char *texture, char *text)
{
    int tmp = get_free_slot_buttons(env);
    sfFloatRect bounds;
    if (tmp == -1)
        return (-1);
    env->buttons_s[tmp].is_valid = true;
    env->buttons_s[tmp].text = my_strdup(text);
    if (env->buttons_s[tmp].text == NULL)
        return destroy_button(env, tmp);
    env->buttons_s[tmp].pos = (sfVector2f) {pos.x, pos.y};
    env->buttons_s[tmp].scale = pos.z;
    env->buttons_s[tmp].sprite = sfSprite_create();
    env->buttons_s[tmp].texture = sfTexture_createFromFile(texture, NULL);
    sfSprite_setTexture(env->buttons_s[tmp].sprite,
        env->buttons_s[tmp].texture, sfTrue);
    sfSprite_setScale(env->buttons_s[tmp].sprite, (sfVector2f) {
        env->buttons_s[tmp].scale, env->buttons_s[tmp].scale});
    sfSprite_setPosition(env->buttons_s[tmp].sprite, env->buttons_s[tmp].pos);
    bounds = sfSprite_getGlobalBounds(env->buttons_s[tmp].sprite);
    sfSprite_setOrigin(env->buttons_s[tmp].sprite,
    (sfVector2f) {bounds.width / 2, bounds.height / 2});
    return (tmp);
}

int destroy_button(env_t *env, int button_id)
{
    if (env->buttons_s[button_id].is_valid)
        sfSprite_destroy(env->buttons_s[button_id].sprite);

    env->buttons_s[button_id].is_valid = false;
    return (0);
}

void destroy_all_buttons(env_t *env)
{
    for (int i = 0; i < MAX_BUTTONS; i++)
        destroy_button(env, i);
}