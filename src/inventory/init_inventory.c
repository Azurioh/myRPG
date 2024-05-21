/*
** EPITECH PROJECT, 2024
** init_inventory
** File description:
** init the inventory
*/

#include "../../include/myrpg.h"

void init_inv_background(myrpg_t *myrpg, inventory_t *inv)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inv->empty_text = sfTexture_createFromFile
        ("./assets/inventory/empty.png", sfFalse);
    inv->image = create_imagefile("assets/inventory/inventory.png",
        resize.x + 480, resize.y + 120, 1.5);
    return;
}

button_t **init_buttons_inv(myrpg_t *myrpg)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};
    button_t **items = malloc(sizeof(button_t *) * 16);
    sfVector2f position;
    int index = 0;

    for (int line = 0; line < 3; line++)
        for (int col = 0; col < 5; col++) {
            position = (sfVector2f){resize.x + 529.5 + col * 51.5,
                resize.y + 265 + line * 51.5};
            items[index] = init_button(my_nbr_to_str(index),
                position,
                "./assets/inventory/empty.png", &change_current_item);
            items[index]->initial_scaling = 1.4;
            sfSprite_setScale(items[index]->image_sprite,
                (sfVector2f){1.4, 1.4});
            index += 1;
        }
    return items;
}

void init_inv_texts(myrpg_t *myrpg, inventory_t *inventory)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};
    sfFont *font = sfFont_createFromFile("./assets/alagard.ttf");

    inventory->name = create_text("", 20,
        (sfVector2f){resize.x + 510, resize.y + 421}, font);
    inventory->description = create_text("", 15,
        (sfVector2f){resize.x + 510, resize.y + 478}, font);
}

sfSprite **init_equipped_items(myrpg_t *myrpg, inventory_t *inventory)
{
    sfSprite **equipped = malloc(sizeof(item_t *) * 6);
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    inventory->equipped = malloc(sizeof(item_t *) * 5);
    for (int i = 0; i < 5; i++) {
        inventory->equipped[i] = NULL;
        equipped[i] = sfSprite_create();
        sfSprite_setScale(equipped[i], (sfVector2f){1.4, 1.4});
        sfSprite_setPosition(equipped[i],
            (sfVector2f){resize.x + 506 + i * 51.5, resize.y + 562});
        sfSprite_setTexture(equipped[i], NULL, sfFalse);
    }
    equipped[5] = NULL;
    return equipped;
}

inventory_t *init_inventory(myrpg_t *myrpg)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    init_inv_background(myrpg, inventory);
    inventory->buttons = init_buttons_inv(myrpg);
    inventory->buttons[15] = NULL;
    inventory->id = malloc(sizeof(int) * 15);
    for (int i = 0; i < 15; i++)
        inventory->id[i] = - 1;
    inventory->selected_item = NULL;
    init_inv_texts(myrpg, inventory);
    inventory->equipped_sprite = init_equipped_items(myrpg, inventory);
    inventory->action_buttons = init_action_buttons(myrpg);
    inventory->id[0] = 20;
    inventory->id[12] = 11;
    inventory->id[2] = 2;
    inventory->id[11] = 4;
    inventory->id[5] = 0;
    inventory->id[14] = 3;
    return inventory;
}
