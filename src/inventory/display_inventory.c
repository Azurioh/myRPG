/*
** EPITECH PROJECT, 2024
** display_inventory
** File description:
** display elements of inventory
*/

#include "../../include/myrpg.h"

void display_inventory(myrpg_t *myrpg)
{
    sfRenderWindow_drawSprite(myrpg->game_info->window,
    myrpg->player->inventory->image->sprite, NULL);
    return;
}
