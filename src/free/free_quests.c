/*
** EPITECH PROJECT, 2024
** free_quests
** File description:
** Function to free the quests
*/

#include "../../include/myrpg.h"

static void free_quest(quest_t *quest)
{
    if (!quest) {
        return;
    }
    free(quest->name);
    free(quest->description);
    free(quest);
}

void free_quests(quest_list_t *quests)
{
    for (int i = 0; quests->quests[i]; i++) {
        free_quest(quests->quests[i]);
    }
    free(quests->quests);
    free(quests);
}
