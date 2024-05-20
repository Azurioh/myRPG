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
    #include "button.h"
    #define INVENTORY_KEY sfKeyE

typedef struct inventory_s {
    image_t *image;
    int *id;
    button_t **buttons;
    sfTexture *empty_text;
} inventory_t;

void free_inventory(inventory_t *inventory);

#endif /* !INVENTORY_H */
