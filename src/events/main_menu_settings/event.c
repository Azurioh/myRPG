/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** Event handling for the main menu
*/

#include "../../../include/myrpg.h"

static void exec_settings_events(void *args)
{
    myrpg_t *myrpg = args;
    button_t **buttons = SETTINGS->visual_elements->buttons;

    manage_button_event(buttons, myrpg);
}

void load_settings(void *args)
{
    myrpg_t *myrpg = args;

    SETTINGS->show_settings_menu = 1;
    EVENTS->previous_load_function = EVENTS->load_function;
    EVENTS->previous_unload_function = EVENTS->unload_function;
    EVENTS->previous_event_function = EVENTS->event_function;
    EVENTS->previous_display_function = EVENTS->display_function;
    EVENTS->load_function = &load_settings_elements;
    EVENTS->unload_function = &unload_settings;
    EVENTS->event_function = &exec_settings_events;
    EVENTS->display_function = &display_settings;
    EVENTS->load_function(myrpg);
}
