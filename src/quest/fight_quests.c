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
