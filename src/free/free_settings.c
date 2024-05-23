/*
** EPITECH PROJECT, 2024
** free_settings
** File description:
** Function to free the settings
*/

#include "../../include/myrpg.h"

static void free_settings_visual(settings_visual_t *visual)
{
    if (!visual) {
        return;
    }
    sfSprite_destroy(visual->background);
    if (visual->buttons) {
        free_all_buttons(visual->buttons);
    }
    if (visual->texts) {
        free_all_texts(visual->texts);
    }
    free(visual);
}

void free_settings(settings_t *settings)
{
    if (!settings) {
        return;
    }
    sfRenderWindow_destroy(settings->window);
    free(settings->window_size_list);
    free(settings->framerate_list);
    free_settings_visual(settings->visual_elements);
    free(settings);
}
