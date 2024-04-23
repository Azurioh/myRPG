/*
** EPITECH PROJECT, 2024
** free_events
** File description:
** Free the event struct
*/

#include "../../include/myrpg.h"

void free_events(event_t *events)
{
    if (!events) {
        return;
    }
    for (int i = 0; i < 7; i++) {
        free(events->events[i]->event_name);
        free(events->events[i]);
    }
    free(events);
}
