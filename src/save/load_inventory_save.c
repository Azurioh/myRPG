/*
** EPITECH PROJECT, 2024
** load_player_save
** File description:
** Function to load the player
*/

#include "../../include/myrpg.h"

void load_inventory_save(myrpg_t *myrpg, char **options)
{
    inventory_t *inventory = init_inventory(myrpg);

    for (int i = 0; i < 15; i++) {
        inventory->id[i] = atoi(options[i]);
    }
    for (int i = 15; i < 20; i++) {
        if (atoi(options[i]) != -1) {
            inventory->equipped[i - 15] = myrpg->items[atoi(options[i])];
        } else {
            inventory->equipped[i - 15] = NULL;
        }
    }
    INVENTORY = inventory;
}
