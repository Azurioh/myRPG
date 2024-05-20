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
        init_window(SETTINGS, 1);
        SETTINGS->fullscreen = 1;
    } else {
        init_window(SETTINGS, 0);
        SETTINGS->fullscreen = 0;
    }
    return 0;
}
