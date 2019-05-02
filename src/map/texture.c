/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_rpg.h"

sfIntRect get_texture_map(char texture)
{
    switch (texture) {
    case '1':
        return ((sfIntRect) {148, 462, 64, 64});
    case '2':
        return ((sfIntRect) {214, 462, 64, 64});
    case '3':
        return ((sfIntRect) {280, 462, 64, 64});
    case '4':
        return ((sfIntRect) {610, 0, 64, 64});
    case '5':
        return ((sfIntRect) {676, 0, 64, 64});
    case '6':
        return ((sfIntRect) {742, 0, 64, 64});
    case '7':
        return ((sfIntRect) {610, 66, 64, 64});
    case '8':
        return ((sfIntRect) {676, 66, 64, 64});
    case '9':
        return ((sfIntRect) {742, 66, 64, 64});
    }
    return (get_texture_map_2(texture));
}

sfIntRect get_texture_map_2(char texture)
{
    switch (texture) {
    case 'A':
        return ((sfIntRect) {610, 132, 64, 64});
    case 'B':
        return ((sfIntRect) {676, 132, 64, 64});
    case 'C':
        return ((sfIntRect) {742, 132, 64, 64});
    case 'D':
        return ((sfIntRect) {148, 330, 64, 64});
    case 'E':
        return ((sfIntRect) {148, 396, 64, 64});
    case 'F':
        return ((sfIntRect) {214, 396, 64, 64});
    case 'G':
        return ((sfIntRect) {280, 396, 64, 64});
    case 'H':
        return ((sfIntRect) {280, 330, 64, 64});
    }
    return ((sfIntRect) {214, 66, 64, 64});
}