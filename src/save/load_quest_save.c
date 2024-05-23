/*
** EPITECH PROJECT, 2024
** load_quest_save
** File description:
** Function to load the quest of the game
*/

#include "../../include/myrpg.h"

void load_quest_save(myrpg_t *myrpg, char **options)
{
    int i = 0;
    quest_list_t *quests = create_quest_list();

    free_quests(QUESTS);
    QUESTS = quests;
    for (; i < atoi(options[0]); i++) {
        QUESTS->quests[i]->is_unlocked = true;
        QUESTS->quests[i]->nb = QUESTS->quests[i]->nb_required;
        QUESTS->quests[i]->is_validate = true;
    }
    QUESTS->actual_quest = i;
    QUESTS->quests[i]->is_unlocked = true;
    QUESTS->quests[i]->is_validate = false;
    QUESTS->quests[i]->nb = atoi(options[1]);
}
