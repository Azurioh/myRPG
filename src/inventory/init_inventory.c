/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init the inventory
*/

#include "../../include/myrpg.h"

button_t **init_buttons_inv(myrpg_t *myrpg)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};
    button_t **items = malloc(sizeof(button_t *) * 15);
    sfVector2f position;
    int index = 0;

    for (int line = 0; line < 3; line++)
        for (int col = 0; col < 5; col++) {
            position = (sfVector2f){resize.x + 500 + col * 51.5,
                resize.y + 269 + line * 51.5};
            items[index] = init_button(my_nbr_to_str(index),
                position,
                "./assets/inventory/empty.png", NULL);
            items[index]->initial_scaling = 1.4;
            sfSprite_setScale(items[index]->image_sprite,
                (sfVector2f){1.4, 1.4});
            index += 1;
        }
    return items;
}

inventory_t *init_inventory(myrpg_t *myrpg)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->empty_text = sfTexture_createFromFile
        ("assets/inventory/empty.png", sfFalse);
    inventory->image = create_imagefile("assets/inventory/inventory.png",
        resize.x + 450, resize.y + 120, 1.5);
    inventory->buttons = init_buttons_inv(myrpg);
    inventory->buttons[15] = NULL;
    inventory->id = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++)
        inventory->id[i] = - 1;
    inventory->id[1] = 20;
    inventory->id[12] = 11;
    inventory->id[11] = 4;
    inventory->id[14] = 3;
    return inventory;
}
