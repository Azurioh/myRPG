/*
** EPITECH PROJECT, 2024
** mute_sound.c
** File description:
** Functions to mute specific sound in the game
*/

#include "../../include/myrpg.h"

int mute_music(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->music_muted == 1) {
        game_info->music_muted = 0;
    } else {
        game_info->music_muted = 1;
    }
    return 0;
}

int mute_sound(game_t *game_info)
{
    if (!game_info) {
        return -1;
    }
    if (game_info->sound_muted == 1) {
        game_info->sound_muted = 0;
    } else {
        game_info->sound_muted = 1;
    }
    return 0;
}
