/*
** EPITECH PROJECT, 2024
** init_program.c
** File description:
** Function to init the program and start the game
*/

#include "../../include/myrpg.h"

static myrpg_t *init_myrpg(void)
{
    myrpg_t *myrpg = malloc(sizeof(myrpg_t));

    myrpg->game_open = 1;
    myrpg->settings = init_settings();
    myrpg->events = malloc(sizeof(event_t));
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    myrpg->player = NULL;
    myrpg->hud = NULL;
    myrpg->game_info = malloc(sizeof(game_t));
    myrpg->game_info->map_view = NULL;
    myrpg->music = NULL;
    myrpg->music_started = false;
    myrpg->game_info->keybinds = init_keybinds();
    load_game_save(myrpg);
    load_main_menu(myrpg);
    return myrpg;
}

int start_game(void)
{
    myrpg_t *myrpg = init_myrpg();

    if (!myrpg) {
        return 84;
    } else {
        return loop(myrpg);
    }
}
