/*
** EPITECH PROJECT, 2024
** show_settings_menu
** File description:
** Function to show the settings menu or not
*/

#include "../../include/myrpg.h"

void show_settings_menu(button_t *button, void *args)
{
    myrpg_t *myrpg = args;
    enum event_name tmp;

    (void) button;
    if (myrpg->settings->show_settings_menu == 0) {
        myrpg->settings->show_settings_menu = 1;
        tmp = myrpg->list_of_events->actual_event;
        myrpg->list_of_events->actual_event = SETTINGS_EVT;
        myrpg->list_of_events->previous_event = tmp;
    } else {
        myrpg->settings->show_settings_menu = 0;
        tmp = myrpg->list_of_events->previous_event;
        myrpg->list_of_events->actual_event = tmp;
        myrpg->list_of_events->previous_event = SETTINGS_EVT;
    }
}
