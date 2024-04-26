/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"

void free_myrpg(myrpg_t *myrpg)
{
    if (!myrpg) {
        return;
    }
    free_player(myrpg->player);
    free_game(myrpg->game_info);
    free_events(myrpg->list_of_events);
    sfSprite_destroy(myrpg->background);
    free_all_buttons(myrpg->buttons);
    free_hud(myrpg->hud);
    free_inventory(myrpg->player->inventory);
    free(myrpg);
}
