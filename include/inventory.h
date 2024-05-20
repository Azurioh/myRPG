/*
** EPITECH PROJECT, 2024
** inventory
** File description:
** inventory
*/

#ifndef INVENTORY_H
    #define INVENTORY_H
    #include <SFML/Graphics.h>
    #include "hud.h"
    #include "game.h"
    #define INVENTORY_KEY sfKeyE

typedef struct item_inv_s {
    int item_id;
    sfVector2f position;
    sfSprite *sprite;
} item_inv_t;

typedef struct inventory_s {
    image_t *image;

    item_inv_t **items;
} inventory_t;

void free_inventory(inventory_t *inventory);

#endif /* !INVENTORY_H */
