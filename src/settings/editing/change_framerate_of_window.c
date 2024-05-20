/*
** EPITECH PROJECT, 2024
** change_framerate_of_window
** File description:
** Function to change the framerate for the game window
*/

#include "../../../include/myrpg.h"

int decrease_framerate_of_window(settings_t *settings)
{
    if (!settings || !settings->framerate_list) {
        return -1;
    }
    if (settings->actual_framerate == 0) {
        return 0;
    }
    settings->actual_framerate--;
    sfRenderWindow_setFramerateLimit(settings->window,
        settings->framerate_list[settings->actual_framerate]);
    return 0;
}

int increase_framerate_of_window(settings_t *settings)
{
    if (!settings || !settings->framerate_list) {
        return -1;
    }
    if (settings->actual_framerate == 7) {
        return 0;
    }
    settings->actual_framerate++;
    sfRenderWindow_setFramerateLimit(settings->window,
        settings->framerate_list[settings->actual_framerate]);
    return 0;
}
