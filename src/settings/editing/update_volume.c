/*
** EPITECH PROJECT, 2024
** update_volume.c
** File description:
** Functions to update the volume
*/

#include "../../../include/myrpg.h"

int increase_sound_volume(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS) {
        return -1;
    }
    if (SETTINGS->sound_volume == 100) {
        return 0;
    }
    SETTINGS->sound_volume += 10;
    sfMusic_setVolume(myrpg->music, SETTINGS->music_volume);
    return 0;
}

int decrease_sound_volume(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS) {
        return -1;
    }
    if (SETTINGS->sound_volume == 0) {
        return 0;
    }
    SETTINGS->sound_volume -= 10;
    sfMusic_setVolume(myrpg->music, SETTINGS->music_volume);
    return 0;
}

int increase_music_volume(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS) {
        return -1;
    }
    if (SETTINGS->music_volume == 100) {
        return 0;
    }
    SETTINGS->music_volume += 10;
    sfMusic_setVolume(myrpg->music, SETTINGS->music_volume);
    fflush(stdout);
    return 0;
}

int decrease_music_volume(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS) {
        return -1;
    }
    if (SETTINGS->music_volume == 0) {
        return 0;
    }
    SETTINGS->music_volume -= 10;
    sfMusic_setVolume(myrpg->music, SETTINGS->music_volume);
    return 0;
}
