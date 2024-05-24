/*
** EPITECH PROJECT, 2024
** update_skill.c
** File description:
** Functions to update a skill
*/

#include "../../include/myrpg.h"

int update_skill(player_t *player, unsigned int skill_index)
{
    skills_t *skill_to_upgrade;

    if (!player || skill_index > 3) {
        return -1;
    }
    if (player->skills[skill_index]->is_max_level == 1) {
        return 0;
    }
    if (player->nb_skills_to_upgrade == 0) {
        return 0;
    }
    skill_to_upgrade = player->skills[skill_index];
    skill_to_upgrade->level++;
    if (skill_to_upgrade->unlocked == 0)
        skill_to_upgrade->unlocked = 1;
    if (skill_to_upgrade->level == skill_to_upgrade->max_level) {
        skill_to_upgrade->is_max_level = 1;
    }
    player->nb_skills_to_upgrade--;
    return 0;
}
