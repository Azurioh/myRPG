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
    #include "item.h"

typedef struct player_stats_info_s {
    sfSprite *background;
    sfText **texts;
} player_stats_info_t;

typedef struct inventory_s {
    image_t *image;
    int *id;
    button_t **buttons;
    sfTexture *empty_text;
    item_t *selected_item;
    button_t *selected_slot;
    sfText *name;
    sfText *description;
    item_t **equipped;
    sfSprite **equipped_sprite;
    button_t **action_buttons;
    player_stats_info_t *stats;
    sfSprite *stats_sprite;
    sfText **player_stats;

} inventory_t;

void free_inventory(inventory_t *inventory);
void use_item(button_t *button, void *args);
void drop_item(button_t *button, void *args);
int add_item_in_inv(inventory_t *inventory, int item_id);

#endif /* !INVENTORY_H */
