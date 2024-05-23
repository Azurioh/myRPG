/*
** EPITECH PROJECT, 2024
** init_player_skills.c
** File description:
** Function to init the skills of the player
*/

#include "../../include/myrpg.h"

static skills_t *init_skill(char *name, int level, int unlocked, int max_level)
{
    skills_t *skill = malloc(sizeof(skills_t));

    if (!skill) {
        return NULL;
    }
    skill->name = name;
    skill->level = level;
    skill->unlocked = unlocked;
    skill->max_level = max_level;
    skill->is_max_level = 0;
    return skill;
}

skills_t **init_player_skills(void)
{
    skills_t **player_skills = malloc(sizeof(skills_t *) * 4);

    if (!player_skills) {
        return NULL;
    }
    player_skills[0] = init_skill(strdup("Hache du Viking"), 0, 1, 4);
    player_skills[1] = init_skill(strdup("Lancer de hache"), 0, 0, 3);
    player_skills[2] = init_skill(strdup("Hydromel"), 0, 0, 2);
    player_skills[3] = init_skill(strdup("Rage du viking"), 0, 0, 1);
    return player_skills;
}
