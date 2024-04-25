/*
** EPITECH PROJECT, 2024
** load_settings_buttons.c
** File description:
** Function to load the buttons of the settings menu
*/

#include "../../include/myrpg.h"

static void manage_settings_button_action(button_t *button, void *args)
{
    myrpg_t *myrpg = args;
    game_t *game_info = myrpg->game_info;

    if (strcmp(button->button_name, "decrease_fps") == 0)
        decrease_framerate_of_window(game_info);
    if (strcmp(button->button_name, "decrease_resolution") == 0)
        decrease_size_of_window(game_info);
    if (strcmp(button->button_name, "decrease_music") == 0)
        decrease_music_volume(game_info);
    if (strcmp(button->button_name, "decrease_sound") == 0)
        decrease_sound_volume(game_info);
    if (strcmp(button->button_name, "increase_fps") == 0)
        increase_framerate_of_window(game_info);
    if (strcmp(button->button_name, "increase_resolution") == 0)
        increase_size_of_window(game_info);
    if (strcmp(button->button_name, "increase_music") == 0)
        increase_music_volume(game_info);
    if (strcmp(button->button_name, "increase_sound") == 0)
        increase_sound_volume(game_info);
}

static void init_left_choice_button(button_t **buttons, settings_t *settings)
{
    buttons[0] = init_button("decrease_fps",
        (sfVector2f){750 * settings->scaling, 450 * settings->scaling},
        "assets/left-choice-button.png", &manage_settings_button_action);
    buttons[2] = init_button("decrease_resolution",
        (sfVector2f){1070 * settings->scaling, 450 * settings->scaling},
        "assets/left-choice-button.png", &manage_settings_button_action);
    buttons[4] = init_button("decrease_music",
        (sfVector2f){750 * settings->scaling, 700 * settings->scaling},
        "assets/left-choice-button.png", &manage_settings_button_action);
    buttons[6] = init_button("decrease_sound",
        (sfVector2f){1070 * settings->scaling, 700 * settings->scaling},
        "assets/left-choice-button.png", &manage_settings_button_action);
    for (int i = 0; i <= 6; i += 2) {
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){settings->scaling * 2, settings->scaling * 2});
    }
}

static void init_right_choice_button(button_t **buttons, settings_t *settings)
{
    buttons[1] = init_button("increase_fps",
        (sfVector2f){850 * settings->scaling, 450 * settings->scaling},
        "assets/right-choice-button.png", &manage_settings_button_action);
    buttons[3] = init_button("increase_resolution",
        (sfVector2f){1170 * settings->scaling, 450 * settings->scaling},
        "assets/right-choice-button.png", &manage_settings_button_action);
    buttons[5] = init_button("increase_music",
        (sfVector2f){850 * settings->scaling, 700 * settings->scaling},
        "assets/right-choice-button.png", &manage_settings_button_action);
    buttons[7] = init_button("increase_sound",
        (sfVector2f){1170 * settings->scaling, 700 * settings->scaling},
        "assets/right-choice-button.png", &manage_settings_button_action);
    for (int i = 1; i <= 7; i += 2) {
        sfSprite_setScale(buttons[i]->image_sprite,
            (sfVector2f){settings->scaling * 2, settings->scaling * 2});
    }
}

button_t **load_settings_buttons(settings_t *settings)
{
    button_t **buttons = malloc(sizeof(button_t *) * 10);

    if (!buttons) {
        return NULL;
    }
    init_left_choice_button(buttons, settings);
    init_right_choice_button(buttons, settings);
    buttons[8] = init_button("quit",
        (sfVector2f){950 * settings->scaling, 800 * settings->scaling},
        "assets/quit-button.png", &show_settings_menu);
    sfSprite_setScale(buttons[8]->image_sprite, (sfVector2f){0.5, 0.5});
    buttons[9] = NULL;
    return buttons;
}
