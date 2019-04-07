/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

void init_fonts(env_t *env)
{
    env->core_s.f_oetz = sfFont_createFromFile(FONT_OETZ);
}