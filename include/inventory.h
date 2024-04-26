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

typedef struct inventory_s {
    image_t *image;
} inventory_t;

inventory_t *init_inventory(void);
void free_inventory(inventory_t *inventory);

#endif /* !INVENTORY_H */
