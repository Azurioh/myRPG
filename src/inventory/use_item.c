/*
** EPITECH PROJECT, 2024
** drop_item
** File description:
** drop an item
*/
#include "../../include/myrpg.h"

void update_equipment(myrpg_t *myrpg, int i)
{
    button_t *button = INVENTORY->selected_slot;
    item_t *item = INVENTORY->selected_item;
    int slot = atoi(button->button_name);
    int old_id = -1;

    if (strcmp(item->name, "Hache du Papa") == 0)
        QUESTS->quests[0]->nb++;
    if (INVENTORY->equipped[i] == NULL) {
        INVENTORY->id[slot] = -1;
        INVENTORY->equipped[i] = item;
    } else {
        INVENTORY->id[slot] = -1;
        old_id = INVENTORY->equipped[i]->item_id;
        INVENTORY->equipped[i] = item;
        add_item_in_inv(INVENTORY, old_id);
    }
    INVENTORY->selected_item = NULL;
    INVENTORY->selected_slot = NULL;
    return erase_text(myrpg);
}

void heal_player(myrpg_t *myrpg)
{
    item_t *item = myrpg->player->inventory->selected_item;
    button_t *button = myrpg->player->inventory->selected_slot;
    int slot = atoi(button->button_name);

    if (myrpg->player->life >= 100)
        return;
    increase_player_life(myrpg->player, item->strength);
    myrpg->player->inventory->selected_item = NULL;
    myrpg->player->inventory->selected_slot = NULL;
    myrpg->player->inventory->id[slot] = -1;
    return erase_text(myrpg);
}

void use_item(button_t *button, void *args)
{
    myrpg_t *myrpg = (myrpg_t *)args;

    (void)button;
    if (myrpg->player->inventory->selected_item == NULL)
        return;
    switch (myrpg->player->inventory->selected_item->type) {
        case (WEAPON):
            return update_equipment(myrpg, 0);
        case (HELMET):
            return update_equipment(myrpg, 1);
        case (CHESTPLATE):
            return update_equipment(myrpg, 2);
        case (TROUSERS):
            return update_equipment(myrpg, 3);
        case (BOOTS):
            return update_equipment(myrpg, 4);
        case (HEAL):
            return heal_player(myrpg);
    }
    return;
}
