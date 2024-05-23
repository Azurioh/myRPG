/*
** EPITECH PROJECT, 2024
** inventory_quests
** File description:
** Function to update quests with the inventory
*/

#include "../../include/myrpg.h"

static bool check_full_equipments(inventory_t *inventory)
{
    for (int i = 0; i < 5; i++) {
        if (!inventory->equipped[i]) {
            return false;
        }
    }
    return true;
}

void inventory_quests(myrpg_t *myrpg)
{
    if (QUESTS->quests[0]->is_validate == 0) {
        if (INVENTORY->equipped[0] && INVENTORY->equipped[0]->item_id == 5) {
            QUESTS->quests[0]->nb++;
            return update_quest(QUESTS);
        }
    }
    if (QUESTS->quests[6]->is_validate == 0) {
        if (check_full_equipments(INVENTORY) == true) {
            QUESTS->quests[6]->nb++;
            return update_quest(QUESTS);
        }
    }
}
