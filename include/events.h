/*
** EPITECH PROJECT, 2024
** events.h
** File description:
** All struct and protos for the events
*/

#ifndef EVENT_H
    #define EVENT_H
    #include <SFML/Graphics.h>

enum event_name {
    MAIN_MENU_EVT = 0,
    CINEMATIC_EVT,
    MISSION_EVT,
    CHATTING_EVT,
    FIGHT_EVT,
    PAUSE_EVT,
    SETTINGS_EVT,
};

typedef struct event_item_s {
    char *event_name;
    sfEvent event;
    void (*event_function)(void *);
} event_item_t;

typedef struct event_s {
    enum event_name actual_event;
    event_item_t **events;
} event_t;

void free_events(event_t *events);

#endif
