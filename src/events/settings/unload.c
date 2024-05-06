/*
** EPITECH PROJECT, 2024
** unload.c
** File description:
** Function to unload settings menu
*/

#include "../../../include/myrpg.h"

void unload_settings(void *args)
{
    myrpg_t *myrpg = args;

    SETTINGS->show_settings_menu = 0;
    EVENTS->load_function = EVENTS->previous_load_function;
    EVENTS->unload_function = EVENTS->previous_unload_function;
    EVENTS->event_function = EVENTS->previous_event_function;
    EVENTS->display_function = EVENTS->previous_display_function;
    sfSprite_destroy(SETTINGS->visual_elements->background);
    for (int i = 0; SETTINGS->visual_elements->buttons[i]; i++)
        free_button(SETTINGS->visual_elements->buttons[i]);
    for (int i = 0; SETTINGS->visual_elements->texts[i]; i++)
        sfText_destroy(SETTINGS->visual_elements->texts[i]);
    free(SETTINGS->visual_elements->buttons);
    free(SETTINGS->visual_elements->texts);
    free(SETTINGS->visual_elements);
    EVENTS->load_function(myrpg);
}
