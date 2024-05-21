/*
** EPITECH PROJECT, 2024
** drop_item
** File description:
** drop an item
*/
#include "../../include/myrpg.h"

void drop_item(button_t *button, void *args)
{
    myrpg_t *myrpg = (myrpg_t *)args;
    inventory_t *inventory = myrpg->player->inventory;
    int slot = atoi(button->button_name);
    int item_id = inventory->id[slot];

    if (item_id == -1) {
        return;
    }
    inventory->selected_slot = button;
    inventory->selected_item = myrpg->items[item_id];
    sfText_setString(inventory->name, inventory->selected_item->name);
    sfText_setString(inventory->description,
        inventory->selected_item->description);
    return;
}
