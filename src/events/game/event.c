/*
** EPITECH PROJECT, 2024
** event.c
** File description:
** Function used to manage events for the game
*/

#include "../../../include/myrpg.h"

static int toggle_boolean(int bolean)
{
    if (bolean == true) {
        return false;
    } else {
        return true;
    }
}

static void manage_escape_key_game(myrpg_t *myrpg)
{
    if (EVENTS->event.key.code == sfKeyEscape) {
        if (myrpg->is_inventory == 1) {
            myrpg->is_inventory = 0;
        }
        if (GAME_INFO->show_menu == 2) {
            free(GAME_INFO->game_menu);
            GAME_INFO->game_menu = init_game_menu(GAME_INFO, SETTINGS);
            GAME_INFO->show_menu = 1;
        }
        GAME_INFO->show_menu = toggle_boolean(GAME_INFO->show_menu);
    }
}

static void open_skills(myrpg_t *myrpg)
{
    if (EVENTS->event.type != sfEvtKeyPressed)
        return;
    if (EVENTS->event.key.code == GAME_INFO->keybinds->skills
        && GAME_INFO->show_menu != 1 && QUESTS->quests[0]->is_validate) {
        if (GAME_INFO->show_menu == 2) {
            free(GAME_INFO->game_menu);
            GAME_INFO->game_menu = init_game_menu(GAME_INFO, SETTINGS);
            GAME_INFO->show_menu = 0;
        } else {
            init_skills_menu(myrpg);
            GAME_INFO->show_menu = 2;
        }
    }
}

void draw_rectangle(myrpg_t *myrpg)
{
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawRectangleShape(myrpg->settings->window,
            myrpg->portal->portal_pos[i]->rect, NULL);
    }
}

static void sprint(myrpg_t *myrpg)
{
    if (EVENTS->event.key.code == GAME_INFO->keybinds->sprint) {
        PLAYER->sprinting = toggle_boolean(PLAYER->sprinting);
    }
}

static void exec_game_events(void *args)
{
    myrpg_t *myrpg = args;

    if (myrpg->is_inventory == 1) {
        manage_button_event(myrpg->player->inventory->buttons, myrpg);
        manage_button_event(myrpg->player->inventory->action_buttons, myrpg);
    }
    if (GAME_INFO->show_menu > 0)
        manage_button_event(GAME_INFO->game_menu->buttons, myrpg);
    if (EVENTS->event.type == sfEvtKeyPressed) {
        if (EVENTS->event.key.code == GAME_INFO->keybinds->open_inventory
            && GAME_INFO->show_menu == sfFalse) {
            myrpg->is_inventory = toggle_boolean(myrpg->is_inventory);
        }
        manage_escape_key_game(myrpg);
        sprint(myrpg);
    }
    open_skills(myrpg);
    check_portal(myrpg);
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
