/*
** EPITECH PROJECT, 2024
** buttons_function.c
** File description:
** Function linked to the buttons
*/

#include "../../../../include/myrpg.h"

void manage_increase_buttons(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    if (strcmp(button->button_name, "increase_fps") == 0)
        increase_framerate_of_window(SETTINGS);
    if (strcmp(button->button_name, "increase_resolution") == 0)
        increase_size_of_window(myrpg);
    if (strcmp(button->button_name, "increase_music") == 0)
        increase_music_volume(myrpg);
    if (strcmp(button->button_name, "increase_sound") == 0)
        increase_sound_volume(myrpg);
    if (strcmp(button->button_name, "fullscreen") == 0)
        toggle_fullscreen(myrpg);
    if (strcmp(button->button_name, "controls") == 0)
        start_to_edit_controls(myrpg);
}

void manage_decrease_buttons(button_t *button, void *args)
{
    myrpg_t *myrpg = args;

    if (strcmp(button->button_name, "decrease_fps") == 0)
        decrease_framerate_of_window(SETTINGS);
    if (strcmp(button->button_name, "decrease_resolution") == 0)
        decrease_size_of_window(myrpg);
    if (strcmp(button->button_name, "decrease_music") == 0)
        decrease_music_volume(myrpg);
    if (strcmp(button->button_name, "decrease_sound") == 0)
        decrease_sound_volume(myrpg);
}
