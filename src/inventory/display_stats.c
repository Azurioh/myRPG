/*
** EPITECH PROJECT, 2024
** display_stats
** File description:
** display stats
*/
#include "../../include/myrpg.h"

void display_stats(myrpg_t *myrpg)
{
    inventory_t *inventory = myrpg->player->inventory;

    sfRenderWindow_drawSprite(myrpg->settings->window,
        inventory->stats_sprite, NULL);
    for (int i = 0; inventory->player_stats[i] != NULL; i++) {
        sfRenderWindow_drawText(myrpg->settings->window,
            inventory->player_stats[i], NULL);
    }
}
