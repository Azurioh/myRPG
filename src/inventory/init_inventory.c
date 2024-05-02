/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init the inventory
*/

#include "../../include/myrpg.h"

inventory_t *init_inventory(game_t *game_info)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f center = sfView_getCenter(game_info->map_view);
    sfVector2f size = sfView_getSize(game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->image = create_imagefile("assets/inventory/inventory.png",
    resize.x + 680, resize.y + 120, 2.5);
    return inventory;
}
