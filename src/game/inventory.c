/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

struct inventory_type_t inventory_type_s[MAX_TYPE_ITEMS] = {
    {0, "Knife", "assets/items/knife.png"},
    {1, "Gun", "assets/items/gun.png"}
};

int get_item_by_name(char *name)
{
    for (int i = 0; i < MAX_TYPE_ITEMS; i++) {
        if (my_strcmp(inventory_type_s[i].item_name, name) == 0)
            return (i);
    }
    return (-1);
}