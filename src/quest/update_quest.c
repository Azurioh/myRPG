/*
** EPITECH PROJECT, 2024
** update_quest.c
** File description:
** Function to update the actual quest
*/

#include "../../include/myrpg.h"

void update_quest(quest_list_t *quest_list)
{
    int index_quest = quest_list->actual_quest;
    quest_t *actual_quest = quest_list->quests[index_quest];

    if (actual_quest->nb >= actual_quest->nb_required) {
        actual_quest->is_validate = true;
        quest_list->quests[index_quest + 1]->is_unlocked = true;
        quest_list->actual_quest++;
    }
}
