/*
** EPITECH PROJECT, 2024
** init_settings_struct.c
** File description:
** Function to init the settings_t struct
*/

#include "../../include/myrpg.h"
#include "../../include/generation.h"
#include <SFML/Graphics/View.h>

static sfVideoMode *get_window_size_list(void)
{
    sfVideoMode *window_size = malloc(sizeof(sfVideoMode) * 3);

    window_size[0] = (sfVideoMode){ 1280, 720, 32 };
    window_size[1] = (sfVideoMode){ 1920, 1080, 32 };
    window_size[2] = (sfVideoMode){ 2560, 1440, 32 };
    return window_size;
}

static unsigned int *get_framerate_list(void)
{
    unsigned int *framerate_list = malloc(sizeof(int) * 8);

    framerate_list[0] = 30;
    framerate_list[1] = 60;
    framerate_list[2] = 90;
    framerate_list[3] = 120;
    framerate_list[4] = 144;
    framerate_list[5] = 165;
    framerate_list[6] = 240;
    framerate_list[7] = 360;
    return framerate_list;
}

settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    if (!settings) {
        return NULL;
    }
    settings->show_settings_menu = 0;
    settings->actual_window_size = 1;
    settings->actual_framerate = 1;
    settings->sound_volume = 50;
    settings->music_volume = 50;
    settings->sound_muted = 0;
    settings->music_muted = 0;
    settings->framerate_list = get_framerate_list();
    settings->scaling = 1;
    settings->window_size_list = get_window_size_list();
    settings->window = NULL;
    settings->fullscreen = 1;
    settings->visual_elements = NULL;
    init_window(settings, settings->fullscreen);
    return settings;
}
