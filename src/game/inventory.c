/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

struct inventory_type_t inventory_type_s[MAX_TYPE_ITEMS] = {
    {0, "Gas mask", "assets/items/5.png", NULL},
    {1, "Rope", "assets/items/6.png", NULL},
    {2, "Handcuffs", "assets/items/7.png", NULL},
    {3, "Hook", "assets/items/9.png", NULL},
    {4, "Mask", "assets/items/12.png", NULL},
    {5, "Boots", "assets/items/13.png", NULL},
    {6, "Lighter", "assets/items/14.png", NULL},
    {7, "Lighter", "assets/items/14.png", NULL},
    {8, "Backpack", "assets/items/21.png", NULL},
    {9, "Matches", "assets/items/22.png", NULL},
    {10, "Key", "assets/items/key.png", NULL}
};

void init_textures_inventory(void)
{
    for (int i = 0; i < MAX_TYPE_ITEMS; i++) {
        inventory_type_s[i].t_item =
        sfTexture_createFromFile(inventory_type_s[i].item_texture, NULL);
    }
}

void game_display_inventory(env_t *env)
{
    sfVector2f pos = sfView_getCenter(env->game_s.view);
    sfSprite_setPosition(env->game_s.s_inventory, pos);
    sfRenderWindow_drawSprite(env->core_s.window, env->game_s.s_inventory,
    NULL);
    for (int i = 0; i < MAX_ITEMS_USER; i++) {
        if (env->game_s.inventory[i] == -1)
            continue;
        sfVector2f tmp_pos = {
            (pos.x - (395 / 2)) + (95 * (i % 4)) + 10,
            (pos.y - 66) + ((i / 4) * 95) + 10
        };
        sfSprite *tmp_sprite = sfSprite_create();
        sfSprite_setTexture(tmp_sprite,
        inventory_type_s[env->game_s.inventory[i]].t_item, sfTrue);
        sfSprite_setOrigin(tmp_sprite, (sfVector2f) {0, 0});
        sfSprite_setPosition(tmp_sprite, tmp_pos);
        sfRenderWindow_drawSprite(env->core_s.window, tmp_sprite, NULL);
        sfSprite_destroy(tmp_sprite);
    }
}

int get_item_by_name(char *name)
{
    for (int i = 0; i < MAX_TYPE_ITEMS; i++) {
        if (my_strcmp(inventory_type_s[i].item_name, name) == 0)
            return (i);
    }
    return (-1);
}

int user_has_item(env_t *env, char *name)
{
    int item_id = get_item_by_name(name);

    if (item_id == -1)
        return (-1);
    for (int i = 0; i < MAX_ITEMS_USER; i++) {
        if (env->game_s.inventory[i] == item_id)
            return (1);
    }
    return (0);
}

int add_item_user(env_t *env)
{
    int rand_item = rand() % MAX_TYPE_ITEMS;

    for (int i = 0; i < MAX_ITEMS_USER; i++) {
        if (env->game_s.inventory[i] == -1) {
            env->game_s.inventory[i] = rand_item;
            return (1);
        }
    }
    return (0);
}