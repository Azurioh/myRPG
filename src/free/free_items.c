/*
** EPITECH PROJECT, 2024
** free_items.c
** File description:
** Function to free the items struct
*/

#include "../../include/myrpg.h"

void free_items(item_t **items)
{
    if (!items) {
        return;
    }
    for (int i = 0; items[i]; i++) {
        free(items[i]->name);
        free(items[i]->description);
        sfTexture_destroy(items[i]->texture);
        free(items[i]);
    }
    free(items);
}
