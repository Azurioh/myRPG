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
    for (int i = 0; inventory->buttons[i] != NULL; i++) {
        sfSprite_move(inventory->buttons[i]->image_sprite, offset);
        inventory->buttons[i]->position.x += offset.x;
        inventory->buttons[i]->position.y += offset.y;
    }
    sfText_move(inventory->description, offset);
    sfText_move(inventory->name, offset);
    return;
}
