/*
** EPITECH PROJECT, 2024
** update_volume.c
** File description:
** Functions to update the volume
*/

#include "../../../include/myrpg.h"

int increase_sound_volume(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->sound_volume == 100) {
        return 0;
    }
    settings->sound_volume += 10;
    return 0;
}

int decrease_sound_volume(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->sound_volume == 0) {
        return 0;
    }
    settings->sound_volume -= 10;
    return 0;
}

int increase_music_volume(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->music_volume == 100) {
        return 0;
    }
    settings->music_volume += 10;
    return 0;
}

int decrease_music_volume(settings_t *settings)
{
    if (!settings) {
        return -1;
    }
    if (settings->music_volume == 0) {
        return 0;
    }
    settings->music_volume -= 10;
    return 0;
}
