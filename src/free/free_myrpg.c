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
    sfSprite_destroy(myrpg->background);
    free_all_buttons(myrpg->buttons);
    free(myrpg);
}
