/*
** EPITECH PROJECT, 2024
** disable_buttons
** File description:
** Functions to enable or disable the different buttons of the settings menu
*/

#include "../../../../include/myrpg.h"

static void disable_button(button_t *button)
{
    sfSprite_setScale(button->image_sprite,
        (sfVector2f){button->initial_scaling, button->initial_scaling});
    sfSprite_setColor(button->image_sprite,
        sfColor_fromRGBA(200, 200, 200, 255));
    button->clickable = sfFalse;
}

static void disable_fps_button(button_t **buttons, settings_t *settings)
{
    if (settings->actual_framerate == 0) {
        disable_button(buttons[0]);
        return;
    }
    if (settings->actual_framerate == 7) {
        disable_button(buttons[1]);
        return;
    }
    buttons[0]->clickable = sfTrue;
    buttons[1]->clickable = sfTrue;
}

static void disable_resolution_button(button_t **buttons, settings_t *settings)
{
    if (settings->actual_window_size == 0) {
        disable_button(buttons[2]);
        return;
    }
    if (settings->actual_window_size == 2) {
        disable_button(buttons[3]);
        return;
    }
    buttons[2]->clickable = sfTrue;
    buttons[3]->clickable = sfTrue;
}

static void disable_sound_button(button_t **buttons, settings_t *settings)
{
    if (settings->sound_volume == 0) {
        disable_button(buttons[4]);
        return;
    }
    if (settings->sound_volume == 100) {
        disable_button(buttons[5]);
        return;
    }
    buttons[4]->clickable = sfTrue;
    buttons[5]->clickable = sfTrue;
}

static void disable_music_button(button_t **buttons, settings_t *settings)
{
    if (settings->music_volume == 0) {
        disable_button(buttons[6]);
        return;
    }
    if (settings->music_volume == 100) {
        disable_button(buttons[7]);
        return;
    }
    buttons[6]->clickable = sfTrue;
    buttons[7]->clickable = sfTrue;
}

void disable_settings_buttons(button_t **buttons, settings_t *settings)
{
    disable_fps_button(buttons, settings);
    disable_resolution_button(buttons, settings);
    disable_music_button(buttons, settings);
    disable_sound_button(buttons, settings);
    for (int i = 0; i < 8; i++) {
        if (buttons[i]->clickable == sfTrue) {
            sfSprite_setColor(buttons[i]->image_sprite,
                sfColor_fromRGBA(255, 255, 255, 255));
        }
    }
}
