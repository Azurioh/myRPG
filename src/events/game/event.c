/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** Function used to manage events for the game
*/

#include "../../../include/myrpg.h"

static int inventory_toggle(int enable)
{
    if (enable == 1) {
        return 0;
    } else {
        return 1;
    }
}

static void manage_escape_key_game(myrpg_t *myrpg)
{
    if (EVENTS->event.key.code == sfKeyEscape
        && myrpg->is_inventory == 1) {
        myrpg->is_inventory = 0;
    }
}

static void exec_game_events(void *args)
{
    myrpg_t *myrpg = args;

    if (myrpg->is_inventory == 1) {
        manage_button_event(myrpg->player->inventory->buttons, myrpg);
    }
    if (EVENTS->event.type == sfEvtKeyPressed) {
        if (EVENTS->event.key.code == GAME_INFO->keybinds->open_inventory) {
            myrpg->is_inventory = inventory_toggle(myrpg->is_inventory);
        }
        manage_escape_key_game(myrpg);
    }
}

void load_game(void *args)
{
    myrpg_t *myrpg = args;

    EVENTS->load_function = &load_game_elements;
    EVENTS->unload_function = NULL;
    EVENTS->event_function = &exec_game_events;
    EVENTS->display_function = &display_game;
    EVENTS->previous_display_function = NULL;
}
