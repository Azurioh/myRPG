/*
** EPITECH PROJECT, 2024
** display_inventory
** File description:
** display elements of inventory
*/

#include "../../include/myrpg.h"

void display_inventory(myrpg_t *myrpg)
{
    if (myrpg->is_inventory == 0)
        return;
    sfRenderWindow_drawSprite(SETTINGS->window,
    myrpg->player->inventory->image->sprite, NULL);
    return;
}
