/*
** EPITECH PROJECT, 2024
** loading.c
** File description:
** Function used to load the elements for the game
*/

#include "../../../../include/myrpg.h"

void load_game_elements(void *args)
{
    myrpg_t *myrpg = args;

    myrpg->player = init_player();
    myrpg->game_info = init_game_struct();
    myrpg->hud = init_hud(myrpg->player->name, myrpg->game_info);
    myrpg->player->inventory = init_inventory(myrpg->game_info);
    myrpg->can_interact = 0;
    myrpg->is_inventory = 0;
}
