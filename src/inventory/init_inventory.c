/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init the inventory
*/

#include "../../include/myrpg.h"

item_inv_t **init_items_inv(myrpg_t *myrpg)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};
    item_inv_t **items = malloc(sizeof(item_inv_t *) * 15);
    int index = 0;

    for (int line = 0; line < 3; line++) {
        for (int col = 0; col < 5; col++) {
            items[index] = malloc(sizeof(item_inv_t));
            items[index]->position = (sfVector2f){resize.x + 428 + col * 50,
                resize.y + 245 + line * 52};
            items[index]->sprite = sfSprite_create();
            sfSprite_setTexture(items[index]->sprite, NULL, sfTrue);
            sfSprite_setPosition(items[index]->sprite, items[index]->position);
            sfSprite_setScale(items[index]->sprite, (sfVector2f){1.4, 1.4});
            items[index]->item_id = -1;
            index += 1;
        }
    }
    return items;
}

inventory_t *init_inventory(myrpg_t *myrpg)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->image = create_imagefile("assets/inventory/inventory.png",
        resize.x + 450, resize.y + 120, 1.5);
    inventory->items = init_items_inv(myrpg);
    inventory->items[15] = NULL;
    inventory->items[1]->item_id = 20;
    inventory->items[12]->item_id = 11;
    inventory->items[11]->item_id = 4;
    inventory->items[14]->item_id = 3;
    return inventory;
}
