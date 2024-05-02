/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** moving the inventory objects
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>

void move_inventory(inventory_t *inventory, int x_move, int y_move)
{
    sfVector2f offset = {x_move, y_move};

    sfSprite_move(inventory->image->sprite, offset);
}
