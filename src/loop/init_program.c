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

    if (!myrpg)
        return NULL;
    myrpg->player = init_player();
    myrpg->game_info = init_game_struct();
    myrpg->hud = init_hud(myrpg->player->name, myrpg->game_info);
    myrpg->portal = portal_map();
    myrpg->player->inventory = init_inventory(myrpg->game_info);
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
    myrpg->list_of_events = NULL;
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    return myrpg;
}

int start_game(void)
{
    myrpg_t *myrpg = init_myrpg();

    if (!myrpg) {
        return 84;
    } else {
        return loop(myrpg);
    return loop(myrpg);
    }
}
