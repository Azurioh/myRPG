/*
** EPITECH PROJECT, 2024
** change_size_of_window.c
** File description:
** Change the size of the actual window
*/

#include "../../../include/myrpg.h"

static int update_scaling(settings_t *settings)
{
    int width = settings->window_size_list[settings->actual_window_size].width;

    return width / 1920;
}

int increase_size_of_window(settings_t *settings)
{
    if (!settings
        || !settings->window
        || !settings->window_size_list) {
        return -1;
    }
    if (settings->actual_window_size == 2) {
        return 0;
    }
    settings->actual_window_size++;
    update_scaling(settings);
    init_window(settings);
    return 0;
}

int decrease_size_of_window(settings_t *settings)
{
    if (!settings
        || !settings->window
        || !settings->window_size_list) {
        return -1;
    }
    if (settings->actual_window_size == 0) {
        return 0;
    }
    settings->actual_window_size--;
    update_scaling(settings);
    init_window(settings);
    return 0;
}
