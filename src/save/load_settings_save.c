/*
** EPITECH PROJECT, 2024
** load_settings_save
** File description:
** Function to save the game in a file
*/

#include "../../include/myrpg.h"

void load_settings_save(myrpg_t *myrpg, char **options)
{
    SETTINGS->scaling = atof(options[0]);
    SETTINGS->actual_window_size = atoi(options[1]);
    SETTINGS->actual_framerate = atoi(options[2]);
    SETTINGS->sound_volume = atoi(options[3]);
    SETTINGS->music_volume = atoi(options[4]);
    SETTINGS->fullscreen = atoi(options[5]);
    init_window(SETTINGS, SETTINGS->fullscreen);
}
