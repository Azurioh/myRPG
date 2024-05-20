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
            items[index]->position = (sfVector2f){resize.x + 730 + col * 86,
                resize.y + 340 + line * 85};
            items[index]->sprite = sfSprite_create();
            sfSprite_setTexture(items[index]->sprite, NULL, sfTrue);
            sfSprite_setPosition(items[index]->sprite, items[index]->position);
            sfSprite_setScale(items[index]->sprite, (sfVector2f){2, 2});
            items[index]->item_id = -1;
            //("assets/inventory/chestplate/Icon44.png", items[index]->position.x, items[index]->position.y, 2);
            index += 1;
        }
    }
    items[index] = NULL;
    return items;
}

inventory_t *init_inventory(myrpg_t *myrpg)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->image = create_imagefile("assets/inventory/inventory.png",
        resize.x + 680, resize.y + 120, 2.5);
    inventory->items = init_items_inv(myrpg);
    
    // sfTexture *texture = sfTexture_createFromFile("assets/inventory/heal/petite_popo.png", NULL);
    // sfSprite_setTexture(inventory->items[0]->sprite,  texture, sfTrue);
    inventory->items[1]->item_id = 20;
    inventory->items[12]->item_id = 11;
    inventory->items[11]->item_id = 4;
    inventory->items[9]->item_id = 0;
    return inventory;
}
