/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"

void free_inventory(inventory_t *inventory)
{
    if (inventory == NULL) {
        return;
    }
    free_image(inventory->image);
    return;
}
