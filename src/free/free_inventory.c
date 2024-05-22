/*
** EPITECH PROJECT, 2024
** free_inventory.c
** File description:
** Function to free the inventory struct
*/

#include "../../include/myrpg.h"

static void free_stat_inventory(inventory_t *inventory)
{
    sfSprite_destroy(inventory->stats_sprite);
    for (int i = 0; inventory->player_stats[i]; i++) {
        sfText_destroy(inventory->player_stats[i]);
    }
    free(inventory->player_stats);
}

void free_inventory(inventory_t *inventory)
{
    if (!inventory)
        return;
    free_image(inventory->image);
    free(inventory->id);
    free_all_buttons(inventory->buttons);
    free(inventory->buttons);
    sfText_destroy(inventory->name);
    sfText_destroy(inventory->description);
    for (int i = 0; inventory->equipped_sprite[i]; i++)
        sfSprite_destroy(inventory->equipped_sprite[i]);
    free(inventory->equipped_sprite);
    free_all_buttons(inventory->action_buttons);
    free_stat_inventory(inventory);
    free(inventory);
    return;
}
