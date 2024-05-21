/*
** EPITECH PROJECT, 2024
** drop_item
** File description:
** drop an item
*/
#include "../../include/myrpg.h"

void update_equipment(inventory_t *inventory, int i)
{
    button_t *button = inventory->selected_slot;
    item_t *item = inventory->selected_item;
    int slot = atoi(button->button_name);
    int old_id = -1;

    if (inventory->equipped[i] == NULL) {
        inventory->id[slot] = -1;
        inventory->equipped[i] = item;
    } else {
        inventory->id[slot] = -1;
        old_id = inventory->equipped[i]->item_id;
        inventory->equipped[i] = item;
        add_item_in_inv(inventory, old_id);
    }
    inventory->selected_item = NULL;
    inventory->selected_slot = NULL;
}

void use_item(button_t *button, void *args)
{
    myrpg_t *myrpg = (myrpg_t *)args;

    (void)button;
    if (myrpg->player->inventory->selected_item == NULL)
        return;
    switch (myrpg->player->inventory->selected_item->type) {
        case (WEAPON):
            return update_equipment(myrpg->player->inventory, 0);
        case (HELMET):
            return update_equipment(myrpg->player->inventory, 1);
        case (CHESTPLATE):
            return update_equipment(myrpg->player->inventory, 2);
        case (TROUSERS):
            return update_equipment(myrpg->player->inventory, 3);
        case (BOOTS):
            return update_equipment(myrpg->player->inventory, 4);
        case (HEAL):
            return update_equipment(myrpg->player->inventory, 1);
    }
    return;
}
