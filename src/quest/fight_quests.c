/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"

void fight_quests(myrpg_t *myrpg)
{
    if (QUESTS->quests[4]->is_validate == false && PLAYER->level >= 2) {
        QUESTS->quests[4]->nb++;
        update_quest(QUESTS);
    }
    if (QUESTS->quests[9]->is_unlocked == true)
        if (myrpg->mobs[myrpg->fight_infos->enemy_id]->level == 5) {
            QUESTS->quests[9]->nb++;
            add_item_in_inv(INVENTORY, 8);
            add_item_in_inv(INVENTORY, 3);
            return update_quest(QUESTS);
        }
    for (int i = 2; i <= 8; i += 3) {
        if (QUESTS->quests[i]->is_unlocked == true
            && QUESTS->quests[i]->is_validate == false) {
            QUESTS->quests[i]->nb++;
            return update_quest(QUESTS);
        }
    }
}
