/*
** EPITECH PROJECT, 2024
** load_main_menu_events.c
** File description:
** Event handling for the main menu
*/

#include "../../../include/myrpg.h"

static void exec_main_menu_events(void *args)
{
    myrpg_t *myrpg = args;

    manage_button_event(BUTTONS, myrpg);
}

void load_main_menu(void *args)
{
    myrpg_t *myrpg = args;

    EVENTS->load_function = &load_main_menu_elements;
    EVENTS->unload_function = &unload_main_menu;
    EVENTS->event_function = &exec_main_menu_events;
    EVENTS->display_function = &display_main_menu;
    EVENTS->previous_display_function = NULL;
}
