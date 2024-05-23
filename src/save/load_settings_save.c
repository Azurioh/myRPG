/*
** EPITECH PROJECT, 2024
** load_settings_save
** File description:
** Function to save the game in a file
*/

#include "../../include/myrpg.h"

void load_settings_save(myrpg_t *myrpg, char **options)
{
    keybinds_t *keybinds = GAME_INFO->keybinds;

    SETTINGS->scaling = atof(options[0]);
    SETTINGS->actual_window_size = atoi(options[1]);
    SETTINGS->actual_framerate = atoi(options[2]);
    SETTINGS->sound_volume = atoi(options[3]);
    SETTINGS->music_volume = atoi(options[4]);
    SETTINGS->fullscreen = atoi(options[5]);
    keybinds->move_up = atoi(options[6]);
    keybinds->move_down = atoi(options[7]);
    keybinds->move_left = atoi(options[8]);
    keybinds->move_right = atoi(options[9]);
    keybinds->open_inventory = atoi(options[10]);
    keybinds->interact = atoi(options[11]);
    keybinds->skills = atoi(options[12]);
    init_window(SETTINGS, SETTINGS->fullscreen);
}
