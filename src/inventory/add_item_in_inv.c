/*
** EPITECH PROJECT, 2024
** add_item_in_inv
** File description:
** add an item in the inventory
*/
#include "../../include/myrpg.h"

int add_item_in_inv(inventory_t *inventory, int item_id)
{
    int *items = inventory->id;

    for (int i = 0; i < 15; i++) {
        if (items[i] == -1) {
            items[i] = item_id;
            return 0;
        }
    }
    return 1;
}
