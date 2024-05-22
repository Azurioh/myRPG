/*
** EPITECH PROJECT, 2024
** free_player.c
** File description:
** Function to free the player struct
*/

#include "../../include/myrpg.h"

void free_player(player_t *player)
{
    if (!player) {
        return;
    }
    sfSprite_destroy(player->interface->sprite);
    sfClock_destroy(player->interface->clock);
    free(player->interface);
    for (int i = 0; i < 3; i++) {
        free(player->skills[i]->name);
        free(player->skills[i]);
    }
    free(player->skills);
}
