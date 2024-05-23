/*
** EPITECH PROJECT, 2024
** manage_skills_quest.c
** File description:
** Function to manage quests linked to skills
*/

#include "../../include/myrpg.h"

static bool check_if_a_skill_is_maxed(skills_t **skills)
{
    for (int i = 0; i < 3; i++) {
        if (skills[i]->is_max_level == 1) {
            return true;
        }
    }
    return false;
}

static bool check_if_any_skills_have_been_updated(skills_t **skills)
{
    for (int i = 0; i < 3; i++) {
        if (skills[i]->level != 0) {
            return true;
        }
    }
    return false;
}

void manage_skills_quest(myrpg_t *myrpg)
{
    if (check_if_any_skills_have_been_updated(PLAYER->skills) == true
        && QUESTS->quests[1]->is_validate == false) {
        QUESTS->quests[1]->nb++;
        QUESTS->quests[1]->is_validate = true;
        return update_quest(QUESTS);
    }
    if (check_if_a_skill_is_maxed(PLAYER->skills) == true
        && QUESTS->quests[7]->is_validate == false) {
        QUESTS->quests[7]->nb++;
        QUESTS->quests[7]->is_validate = true;
        return update_quest(QUESTS);
    }
}
