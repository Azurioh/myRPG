/*
** EPITECH PROJECT, 2024
** update_volume.c
** File description:
** Functions to update the volume
*/

#include "../../include/myrpg.h"

int increase_sound_volume(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->sound_volume == 100) {
        return 0;
    }
    game_info->sound_volume += 10;
    return 0;
}

int decrease_sound_volume(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->sound_volume == 0) {
        return 0;
    }
    game_info->sound_volume -= 10;
    return 0;
}

int increase_music_volume(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->music_volume == 100) {
        return 0;
    }
    game_info->music_volume += 10;
    return 0;
}

int decrease_music_volume(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->music_volume == 0) {
        return 0;
    }
    game_info->music_volume -= 10;
    return 0;
}
