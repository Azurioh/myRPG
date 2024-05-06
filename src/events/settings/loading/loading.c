/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** Function to load the visual of the settings menu
*/

#include "../../../../include/myrpg.h"

void load_settings_elements(void *args)
{
    myrpg_t *myrpg = args;
    settings_visual_t *visual_elements = malloc(sizeof(settings_visual_t));

    if (!visual_elements) {
        SETTINGS->visual_elements = NULL;
        return;
    }
    visual_elements->background = load_settings_background(SETTINGS->window,
        SETTINGS->scaling);
    visual_elements->buttons = load_settings_buttons(SETTINGS);
    visual_elements->texts = load_settings_texts(SETTINGS);
    SETTINGS->visual_elements = visual_elements;
}
