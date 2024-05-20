/*
** EPITECH PROJECT, 2024
** buttons.c
** File description:
** Function to load the buttons of the settings menu
*/

#include "../../../../include/myrpg.h"

static void manage_settings_button_action(button_t *button, void *args)
{
    myrpg_t *myrpg = args;
    settings_t *settings = myrpg->settings;

    if (strcmp(button->button_name, "decrease_fps") == 0)
        decrease_framerate_of_window(settings);
    if (strcmp(button->button_name, "decrease_resolution") == 0)
        decrease_size_of_window(myrpg);
    if (strcmp(button->button_name, "decrease_music") == 0)
        decrease_music_volume(settings);
    if (strcmp(button->button_name, "decrease_sound") == 0)
        decrease_sound_volume(settings);
    if (strcmp(button->button_name, "increase_fps") == 0)
        increase_framerate_of_window(settings);
    if (strcmp(button->button_name, "increase_resolution") == 0)
        increase_size_of_window(myrpg);
    if (strcmp(button->button_name, "increase_music") == 0)
        increase_music_volume(settings);
    if (strcmp(button->button_name, "increase_sound") == 0)
        increase_sound_volume(settings);
}

static void init_left_choice_button(button_t **buttons, settings_t *settings)
{
    buttons[0] = init_button("decrease_fps",
        (sfVector2f){1150 * settings->scaling, 240 * settings->scaling},
        "assets/less.png", &manage_settings_button_action);
    buttons[2] = init_button("decrease_resolution",
        (sfVector2f){1150 * settings->scaling, 360 * settings->scaling},
        "assets/less.png", &manage_settings_button_action);
    buttons[4] = init_button("decrease_music",
        (sfVector2f){1150 * settings->scaling, 480 * settings->scaling},
        "assets/less.png", &manage_settings_button_action);
    buttons[6] = init_button("decrease_sound",
        (sfVector2f){1150 * settings->scaling, 600 * settings->scaling},
        "assets/less.png", &manage_settings_button_action);
    for (int i = 0; i <= 6; i += 2) {
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){settings->scaling / 1.8, settings->scaling / 1.8});
        buttons[i]->initial_scaling = settings->scaling / 1.8;
    }
}

static void init_right_choice_button(button_t **buttons, settings_t *settings)
{
    buttons[1] = init_button("increase_fps",
        (sfVector2f){1250 * settings->scaling, 240 * settings->scaling},
        "assets/more.png", &manage_settings_button_action);
    buttons[3] = init_button("increase_resolution",
        (sfVector2f){1250 * settings->scaling, 360 * settings->scaling},
        "assets/more.png", &manage_settings_button_action);
    buttons[5] = init_button("increase_music",
        (sfVector2f){1250 * settings->scaling, 480 * settings->scaling},
        "assets/more.png", &manage_settings_button_action);
    buttons[7] = init_button("increase_sound",
        (sfVector2f){1250 * settings->scaling, 600 * settings->scaling},
        "assets/more.png", &manage_settings_button_action);
    for (int i = 1; i <= 7; i += 2) {
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){settings->scaling / 1.8, settings->scaling / 1.8});
        buttons[i]->initial_scaling = settings->scaling / 1.8;
    }
}

static void close_settings(button_t *button, void *args)
{
    (void) button;
    unload_settings(args);
}

static button_t *init_control_button(settings_t *settings)
{
    button_t *button = init_button("controls",
        (sfVector2f){960 * settings->scaling, 730 * settings->scaling},
        "assets/controls_button.png", NULL);

    button->initial_scaling = settings->scaling;
    return button;
}

button_t **load_settings_buttons(settings_t *settings)
{
    button_t **buttons = malloc(sizeof(button_t *) * 11);

    if (!buttons) {
        return NULL;
    }
    init_left_choice_button(buttons, settings);
    init_right_choice_button(buttons, settings);
    buttons[8] = init_control_button(settings);
    buttons[9] = init_button("quit",
        (sfVector2f){960 * settings->scaling, 860 * settings->scaling},
        "assets/quit-button.png", &close_settings);
    buttons[9]->initial_scaling = settings->scaling / 1.5;
    sfSprite_setScale(buttons[9]->image_sprite,
        (sfVector2f){settings->scaling / 1.5, settings->scaling / 1.5});
    buttons[10] = NULL;
    return buttons;
}
