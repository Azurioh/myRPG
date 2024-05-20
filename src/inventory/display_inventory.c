/*
** EPITECH PROJECT, 2024
** display_inventory
** File description:
** display elements of inventory
*/

#include "../../include/myrpg.h"

void update_inventory(myrpg_t *myrpg)
{
    item_inv_t **inv = myrpg->player->inventory->items;
    item_t *item;

    for (int i = 0; inv[i] != NULL; i++) {
        if (inv[i]->item_id != -1) {
            item = myrpg->items[inv[i]->item_id];
            sfSprite_setTexture(inv[i]->sprite, item->texture, sfFalse);
        }
    }
}

void display_inventory(myrpg_t *myrpg)
{
    if (myrpg->is_inventory == 0)
        return;
    update_inventory(myrpg);
    sfRenderWindow_drawSprite(SETTINGS->window,
    myrpg->player->inventory->image->sprite, NULL);
    for (int i = 0; i < 15; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
            myrpg->player->inventory->items[i]->sprite, NULL);
    }
    return;
}
