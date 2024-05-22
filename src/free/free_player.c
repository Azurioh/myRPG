/*
** EPITECH PROJECT, 2024
** free_player.c
** File description:
** Function to free the player struct
*/

#include "../../include/myrpg.h"

static void free_player_interface(player_interface_t *player)
{
    if (!player) {
        return;
    }
    sfSprite_destroy(player->sprite);
    sfClock_destroy(player->clock);
    free(player);
}

static void free_player_skills(skills_t **skills)
{
    if (!skills) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        free(skills[i]->name);
        free(skills[i]);
    }
    free(skills);
}

void free_player(player_t *player)
{
    if (!player)
        return;
    free(player->name);
    free_player_skills(player->skills);
    free_player_interface(player->interface);
    free_inventory(player->inventory);
    free(player);
}
