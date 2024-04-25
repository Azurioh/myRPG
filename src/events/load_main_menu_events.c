/*
** EPITECH PROJECT, 2024
** load_main_menu_events.c
** File description:
** Event handling for the main menu
*/

#include "../../include/myrpg.h"

static void exec_main_menu_events(void *args)
{
    myrpg_t *myrpg = args;
    button_t **buttons = myrpg->buttons;

    manage_button_event(buttons, myrpg);
}

static void display_main_menu(void *args)
{
    myrpg_t *myrpg = args;
    sfRenderWindow *window = myrpg->game_info->window;
    settings_t *settings = myrpg->settings;

    sfRenderWindow_drawSprite(window, myrpg->background, NULL);
    if (settings->show_settings_menu == 0) {
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(window, myrpg->buttons[i]->image_sprite,
                NULL);
        }
    }
}

event_item_t *load_main_menu_events(void)
{
    event_item_t *event_item = malloc(sizeof(event_item_t));

    if (!event_item) {
        return NULL;
    }
    event_item->event_name = strdup("main_menu");
    event_item->event_function = &exec_main_menu_events;
    event_item->display_function = &display_main_menu;
    return event_item;
}
