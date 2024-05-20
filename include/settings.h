/*
** EPITECH PROJECT, 2024
** settings.h
** File description:
** Protos and struct for the settings
*/

#ifndef SETTINGS_H
    #define SETTINGS_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
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
    int fullscreen;
} settings_t;

settings_t *init_settings(void);

int init_window(settings_t *settings, int fullscreen);

int mute_music(settings_t *settings);
int mute_sound(settings_t *settings);

int increase_music_volume(settings_t *settings);
int increase_sound_volume(settings_t *settings);
int increase_framerate_of_window(settings_t *settings);
int increase_size_of_window(void *args);

int decrease_music_volume(settings_t *settings);
int decrease_sound_volume(settings_t *settings);
int decrease_framerate_of_window(settings_t *settings);
int decrease_size_of_window(void *args);

sfSprite *load_settings_background(sfRenderWindow *window,
    float scaling);
#endif
