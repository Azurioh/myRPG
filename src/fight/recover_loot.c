/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** recover the loot item by doing an random
*/

#include "../../include/mobs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int get_loot(mobs_t *mob)
{
    int rarity = 0;
    int val = 0;

    srand(time(NULL));
    val = rand() % 10;
    if (val <= 5)
        rarity = 0;
    if (val > 5 && val <= 7)
        rarity = 1;
    if (val > 7 && val <= 9)
        rarity = 2;
    if (val == 10)
        rarity = 3;
    srand(time(NULL));
    if (rarity == 1 || rarity == 2) {
        return mob->item_loot[rarity][rand() % 5];
    } else {
        return mob->item_loot[rarity][rand() % 6];
    }
}
