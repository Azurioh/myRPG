/*
** EPITECH PROJECT, 2024
** change_size_of_window.c
** File description:
** Change the size of the actual window
*/

#include "../../../include/myrpg.h"

static void update_scaling(settings_t *settings)
{
    float width =
        settings->window_size_list[settings->actual_window_size].width;

    settings->scaling = (width / 1920);
}

int increase_size_of_window(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS
        || !SETTINGS->window
        || !SETTINGS->window_size_list) {
        return -1;
    }
    if (SETTINGS->actual_window_size == 2) {
        return 0;
    }
    SETTINGS->actual_window_size++;
    update_scaling(SETTINGS);
    init_window(SETTINGS);
    EVENTS->load_function(myrpg);
    return 0;
}

int decrease_size_of_window(void *args)
{
    myrpg_t *myrpg = args;

    if (!SETTINGS
        || !SETTINGS->window
        || !SETTINGS->window_size_list) {
        return -1;
    }
    if (SETTINGS->actual_window_size == 0) {
        return 0;
    }
    SETTINGS->actual_window_size--;
    update_scaling(SETTINGS);
    init_window(SETTINGS);
    EVENTS->load_function(myrpg);
    return 0;
}
