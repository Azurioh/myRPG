/*
** EPITECH PROJECT, 2024
** display_inventory
** File description:
** display elements of inventory
*/

#include "../../include/myrpg.h"

void update_equipped_item(myrpg_t *myrpg)
{
    inventory_t *inventory = myrpg->player->inventory;

    for (int i = 0; i < 5; i++) {
        if (inventory->equipped[i] != NULL)
            sfSprite_setTexture(inventory->equipped_sprite[i],
                inventory->equipped[i]->texture, sfFalse);
    }
}

void update_inventory(myrpg_t *myrpg)
{
    button_t **inv = myrpg->player->inventory->buttons;
    int *id = myrpg->player->inventory->id;
    item_t *item;

    for (int i = 0; inv[i] != NULL; i++) {
        if (id[i] != -1) {
            item = myrpg->items[id[i]];
            sfSprite_setTexture(inv[i]->image_sprite, item->texture, sfFalse);
        } else
            sfSprite_setTexture(inv[i]->image_sprite,
                myrpg->player->inventory->empty_text, sfFalse);
    }
}

void display_equipped(inventory_t *inventory, sfRenderWindow *window)
{
    for (int i = 0; inventory->equipped_sprite[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window, inventory->equipped_sprite[i], NULL);
    }
}

void display_inventory(myrpg_t *myrpg)
{
    if (myrpg->is_inventory == 0)
        return;
    update_inventory(myrpg);
    update_equipped_item(myrpg);
    sfRenderWindow_drawSprite(SETTINGS->window,
    myrpg->player->inventory->image->sprite, NULL);
    for (int i = 0; i < 15; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
            myrpg->player->inventory->buttons[i]->image_sprite, NULL);
    }
    sfRenderWindow_drawText(SETTINGS->window,
    myrpg->player->inventory->name, NULL);
    sfRenderWindow_drawText(SETTINGS->window,
    myrpg->player->inventory->description, NULL);
    display_equipped(myrpg->player->inventory, myrpg->settings->window);
    return;
}
