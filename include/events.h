/*
** EPITECH PROJECT, 2024
** events.h
** File description:
** All struct and protos for the events
*/

#ifndef EVENT_H
    #define EVENT_H
    #include <SFML/Graphics.h>
    #include "button.h"
    #include "settings.h"

typedef struct event_s {
    sfEvent event;
    void (*load_function)(void *);
    void (*unload_function)(void *);
    void (*event_function)(void *);
    void (*display_function)(void *);
    void (*previous_load_function)(void *);
    void (*previous_unload_function)(void *);
    void (*previous_event_function)(void *);
    void (*previous_display_function)(void *);
} event_t;

void load_main_menu(void *args);
void load_main_menu_elements(void *args);
void unload_main_menu(void *args);
void display_main_menu(void *args);
void load_main_menu_buttons(void *args);

void load_settings(void *args);
void unload_settings(void *args);
void load_settings_elements(void *args);
void load_settings_event(void *args);
button_t **load_settings_buttons(settings_t *settings);
void display_settings(void *args);
#endif
