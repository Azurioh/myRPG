/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** MyRPG
*/

#include "../../include/myrpg.h"

float check_health_lvl(myrpg_t *myrpg)
{
    int lvl = myrpg->player->skills[2]->level;

    if (lvl == 0)
        return 1.00;
    if (lvl == 1)
        return 1.25;
    if (lvl == 2)
        return 1.5;
    return 1.00;
}

float check_damage_axe_lvl(myrpg_t *myrpg)
{
    int lvl = myrpg->player->skills[0]->level;

    if (lvl == 1)
        return 1.00;
    if (lvl == 2)
        return 1.10;
    if (lvl == 3)
        return 1.20;
    if (lvl == 4)
        return 1.30;
    return 1.00;
}

float check_damage_launch_lvl(myrpg_t *myrpg)
{
    int lvl = myrpg->player->skills[1]->level;

    if (lvl == 0)
        return 1.00;
    if (lvl == 1)
        return 1.10;
    if (lvl == 2)
        return 1.20;
    if (lvl == 3)
        return 1.30;
    return 1.00;
}
