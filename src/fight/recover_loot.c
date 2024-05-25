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
    val = rand() % 1000;
    if (val <= 500)
        rarity = 1;
    if (val > 500 && val <= 790)
        rarity = 2;
    if (val > 790 && val <= 980)
        rarity = 3;
    if (val > 980 && val <= 1000)
        rarity = 4;
    return rarity;
}

int get_loot(myrpg_t *myrpg, mobs_t *mob)
{
    int rarity = 0;

    if (QUESTS->quests[2]->is_unlocked
        && QUESTS->quests[2]->is_validate == false) {
        return 1;
    }
    rarity = get_rarity();
    srand(time(NULL));
    return mob->item_loot[rarity][rand() % 5];
}

void add_item(myrpg_t *myrpg, int i)
{
    int heal_item;

    srand(time(NULL));
    heal_item = get_rarity() - 1;
    add_item_in_inv(myrpg->player->inventory,
        myrpg->mobs[i]->item_loot[0][heal_item]);
    if (rand() % 25 == 3)
        add_item_in_inv(myrpg->player->inventory,
            get_loot(myrpg, myrpg->mobs[i]));
    add_item_in_inv(myrpg->player->inventory, get_loot(myrpg, myrpg->mobs[i]));
}
