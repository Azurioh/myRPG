/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** moving the inventory objects
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>

void move_inventory(inventory_t *inventory, sfVector2f offset)
{
    sfSprite_move(inventory->image->sprite, offset);
    for (int i = 0; inventory->items[i] != NULL; i++) {
        sfSprite_move(inventory->items[i]->sprite, offset);
        inventory->items[i]->position.x += offset.x;
        inventory->items[i]->position.y += offset.y;
    }
}
