/*
** EPITECH PROJECT, 2018
** My Defender
** File description:
** Prototypes of all functions in the program
*/

#include "my_rpg.h"
#include "my.h"

void init_sounds(env_t *env)
{
    env->core_s.m_effects[0] = sfMusic_createFromFile(_SOUNDS_CLICK);
    env->core_s.m_music = sfMusic_createFromFile(_MUSIC_BACKGROUND);
    env->core_s.m_game = sfMusic_createFromFile(_MUSIC_GAME);

    sfMusic_setVolume(env->core_s.m_effects[0], 100.0);
    sfMusic_setVolume(env->core_s.m_music, 100.0);
    sfMusic_setVolume(env->core_s.m_game, 100.0);
    sfMusic_setLoop(env->core_s.m_music, sfTrue);
    sfMusic_setLoop(env->core_s.m_game, sfTrue);
    sfMusic_play(env->core_s.m_music);
}

void set_sounds_music(env_t *env)
{
    float volume = sfMusic_getVolume(env->core_s.m_music);
    sfMusic_setVolume(env->core_s.m_music, (volume >= 100.0 ? 0.0 : 100.0));
    sfMusic_setVolume(env->core_s.m_game, (volume >= 100.0 ? 0.0 : 100.0));
}

void set_sounds_effects(env_t *env)
{
    float volume = sfMusic_getVolume(env->core_s.m_effects[0]);
    sfMusic_setVolume(env->core_s.m_effects[0], (volume >= 100.0 ? 0.0 : 100.0));
}

float get_sounds_music(env_t *env)
{
    return (sfMusic_getVolume(env->core_s.m_music));
}

float get_sounds_effects(env_t *env)
{
    return (sfMusic_getVolume(env->core_s.m_effects[0]));
}