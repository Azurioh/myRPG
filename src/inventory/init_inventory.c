/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init the inventory
*/

#include "../../include/myrpg.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    inventory->image = create_imagefile("assets/inventory/inventory.png",
    680, 100, 2.5);
    return inventory;
}
