/*
** EPITECH PROJECT, 2024
** settings.h
** File description:
** Protos and struct for the settings
*/

#ifndef SETTINGS_H
    #define SETTINGS_H
    #include <SFML/Graphics.h>
    #include "button.h"

typedef struct settings_visual_s {
    sfSprite *background;
    sfText **texts;
    button_t **buttons;
} settings_visual_t;

typedef struct settings_s {
    int show_settings_menu;
    settings_visual_t *visual_elements;
    sfRenderWindow *window;
    sfVideoMode *window_size_list;
    float scaling;
    sfEvent event;
    int actual_window_size;
    unsigned int *framerate_list;
    int actual_framerate;
    int sound_volume;
    int sound_muted;
    int music_volume;
    int music_muted;
} settings_t;

void load_settings_menu(settings_t *settings);
void show_settings_menu(button_t *button, void *args);
#endif
