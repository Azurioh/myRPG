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

typedef struct inventory_s {
    image_t *image;
} inventory_t;

inventory_t *init_inventory(game_t *game_info);
void free_inventory(inventory_t *inventory);

#endif /* !INVENTORY_H */
