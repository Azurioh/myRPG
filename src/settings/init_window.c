/*
** EPITECH PROJECT, 2024
** init_window.c
** File description:
** Function to init the game window
*/

#include "../../include/myrpg.h"

int init_window_fullscreen(settings_t *settings)
{
    sfRenderWindow *window;
    sfVideoMode window_size;

    if (!settings || !settings->window_size_list) {
        return -1;
    }
    window_size = settings->window_size_list[1];
    if (settings->window) {
        sfRenderWindow_destroy(settings->window);
    }
    window = sfRenderWindow_create(window_size, "MyRPG",
        sfClose | sfFullscreen | sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window,
        settings->framerate_list[settings->actual_framerate]);
    settings->window = window;
    return 0;
}

int init_window_windowed(settings_t *settings)
{
    sfRenderWindow *window;
    sfVideoMode window_size;

    if (!settings || !settings->window_size_list) {
        return -1;
    }
    window_size = settings->window_size_list[settings->actual_window_size];
    if (settings->window) {
        sfRenderWindow_destroy(settings->window);
    }
    window = sfRenderWindow_create(window_size, "MyRPG",
        sfClose | sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window,
        settings->framerate_list[settings->actual_framerate]);
    settings->window = window;
    return 0;
}

int init_window(settings_t *settings, int fullscreen)
{
    if (fullscreen == 1) {
        return init_window_fullscreen(settings);
    } else {
        return init_window_windowed(settings);
    }
}
