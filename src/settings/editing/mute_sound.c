/*
** EPITECH PROJECT, 2024
** mute_sound.c
** File description:
** Functions to mute specific sound in the game
*/

#include "../../../include/myrpg.h"

int mute_music(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->music_muted == 1) {
        settings->music_muted = 0;
    } else {
        settings->music_muted = 1;
    }
    return 0;
}

int mute_sound(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->sound_muted == 1) {
        settings->sound_muted = 0;
    } else {
        settings->sound_muted = 1;
    }
    return 0;
}
