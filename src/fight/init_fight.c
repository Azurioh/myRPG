/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Fight initiation
*/

#include "../../include/myrpg.h"

fight_t *init_fight(void)
{
    fight_t *fight_struct = malloc(sizeof(fight_t));

    fight_struct->in_fight = 0;
    return fight_struct;
}
