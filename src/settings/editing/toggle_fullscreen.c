/*
** EPITECH PROJECT, 2024
** toggle_fullscreen
** File description:
** Function to enable or disable the fullscreen
*/

#include "../../../include/myrpg.h"

int toggle_fullscreen(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS) {
        return -1;
    }
    if (SETTINGS->fullscreen == 0) {
        SETTINGS->fullscreen = 1;
        SETTINGS->actual_window_size = 1;
        SETTINGS->scaling = 1;
        init_window(SETTINGS, 1);
        EVENTS->load_function(myrpg);
    } else {
        SETTINGS->fullscreen = 0;
        init_window(SETTINGS, 0);
        EVENTS->load_function(myrpg);
    }
    return 0;
}
