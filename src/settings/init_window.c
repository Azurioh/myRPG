/*
** EPITECH PROJECT, 2024
** init_window.c
** File description:
** Function to init the game window
*/

#include "../../include/myrpg.h"

int init_window(settings_t *settings)
{
    sfRenderWindow *window;
    sfVideoMode window_size;

    if (!settings || !settings->window_size_list) {
        return -1;
    }
    window_size = settings->window_size_list[settings->actual_window_size];
    window = sfRenderWindow_create(window_size, "MyRPG",
        sfClose | sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window,
        settings->framerate_list[settings->actual_framerate]);
    if (settings->window) {
        sfRenderWindow_destroy(settings->window);
    }
    settings->window = window;
    return 0;
}
