/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** recover the loot item by doing an random
*/

#include "../../include/myrpg.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static int get_rarity(void)
{
    int val;
    int rarity;

    srand(time(NULL));
    val = rand() % 100;
    if (val <= 50)
        rarity = 0;
    if (val > 50 && val <= 80)
        rarity = 1;
    if (val > 80 && val <= 100)
        rarity = 2;
    return rarity;
}

int get_loot(myrpg_t *myrpg, mobs_t *mob)
{
    int rarity = 0;

    if (QUESTS->quests[2]->is_unlocked
        && QUESTS->quests[2]->is_validate == false) {
        return 2;
    }
    rarity = get_rarity();
    srand(time(NULL));
    if (rarity == 1 || rarity == 2) {
        return mob->item_loot[rarity][rand() % 5];
    } else {
        return mob->item_loot[rarity][rand() % 6];
    }
}
