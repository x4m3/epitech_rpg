/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my.h"
#include "my_defender.h"

void init_sounds(env_t *env)
{
    env->core_s.m_scroll = sfMusic_createFromFile(_MUSIC_SCROLL);
    env->core_s.m_click = sfMusic_createFromFile(_MUSIC_CLICK);
    env->core_s.m_error = sfMusic_createFromFile(_MUSIC_ERROR);

    sfMusic_setVolume(env->core_s.m_scroll, 100.0);
    sfMusic_setVolume(env->core_s.m_click, 100.0);
    sfMusic_setVolume(env->core_s.m_error, 100.0);
}

void set_sound_effects(env_t *env)
{
    float sound = sfMusic_getVolume(env->core_s.m_click);
    if (sound > 0) {
        sfMusic_setVolume(env->core_s.m_click, 0.0);
        sfMusic_setVolume(env->core_s.m_error, 0.0);
        sfMusic_setVolume(env->core_s.m_scroll, 0.0);
    }
    else {
        sfMusic_setVolume(env->core_s.m_click, 100.0);
        sfMusic_setVolume(env->core_s.m_error, 100.0);
        sfMusic_setVolume(env->core_s.m_scroll, 100.0);
    }
}