/*
** EPITECH PROJECT, 2024
** load_settings_event.c
** File description:
** Event handling for the main menu
*/

#include "../../include/myrpg.h"

static void update_settings_text(sfText **texts, game_t *game_info)
{
    char *resolution = my_nbr_to_str(
        game_info->window_size_list[game_info->actual_window_size].width);

    sfText_setString(texts[4], my_nbr_to_str(
        game_info->framerate_list[game_info->actual_framerate]));
    resolution = strcat(resolution, "x");
    resolution = strcat(resolution, my_nbr_to_str(
        game_info->window_size_list[game_info->actual_window_size].height));
    sfText_setString(texts[5], resolution);
    sfText_setString(texts[6], my_nbr_to_str(game_info->music_volume));
    sfText_setString(texts[7], my_nbr_to_str(game_info->sound_volume));
}

static void display_settings_menu(void *args)
{
    myrpg_t *myrpg = args;
    settings_visual_t *settings_visual = myrpg->settings->visual_elements;
    enum event_name tmp = myrpg->list_of_events->previous_event;
    event_item_t *previous = myrpg->list_of_events->events[tmp];

    previous->display_function(args);
    sfRenderWindow_drawSprite(GAME_INFO->window,
        settings_visual->background, NULL);
    for (int i = 0; settings_visual->buttons[i]; i++) {
        sfRenderWindow_drawSprite(GAME_INFO->window,
            settings_visual->buttons[i]->image_sprite, NULL);
    }
    for (int i = 0; settings_visual->texts[i]; i++) {
        sfRenderWindow_drawText(GAME_INFO->window,
            settings_visual->texts[i], NULL);
    }
    update_settings_text(settings_visual->texts, GAME_INFO);
    return;
}

static void exec_settings_events(void *args)
{
    myrpg_t *myrpg = args;
    button_t **buttons = myrpg->settings->visual_elements->buttons;

    manage_button_event(buttons, myrpg);
}

event_item_t *load_settings_event(void)
{
    event_item_t *event_item = malloc(sizeof(event_item_t));

    if (!event_item) {
        return NULL;
    }
    event_item->event_name = strdup("settings");
    event_item->event_function = &exec_settings_events;
    event_item->display_function = &display_settings_menu;
    return event_item;
}
