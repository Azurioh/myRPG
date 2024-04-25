/*
** EPITECH PROJECT, 2024
** init_events.c
** File description:
** Function to init the events
*/

#include "../../include/myrpg.h"

event_t *init_events(void)
{
    event_t *events = malloc(sizeof(event_t));
    event_item_t **list_of_events = malloc(sizeof(event_item_t *) * 7);

    list_of_events[MAIN_MENU_EVT] = load_main_menu_events();
    list_of_events[SETTINGS_EVT] = load_settings_event();
    events->events = list_of_events;
    events->actual_event = MAIN_MENU_EVT;
    events->previous_event = MAIN_MENU_EVT;
    return events;
}
