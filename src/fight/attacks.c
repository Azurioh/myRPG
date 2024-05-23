/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** All the attacks for my RPG
*/

#include "../../include/fight.h"
#include <stdio.h>
#include <string.h>

char *axe_throw(void *fight_inf)
{
    fight_t *fight = fight_inf;
    char *ret = strdup("a : 20");

    (void) fight;
    return ret;
}

char *another_attack(void *fight_inf)
{
    fight_t *fight = fight_inf;
    char *ret = strdup("b : 20");

    (void) fight;
    return ret;
}

char *drink_hydromel(void *fight_inf)
{
    fight_t *fight = fight_inf;
    char *ret = strdup("c : 20");

    (void) fight;
    return ret;
}

char *angry_guy(void *fight_inf)
{
    fight_t *fight = fight_inf;
    char *ret = strdup("d : 2");

    (void) fight;
    return ret;
}
