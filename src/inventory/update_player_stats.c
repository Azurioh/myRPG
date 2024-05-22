/*
** EPITECH PROJECT, 2024
** update_player_stats
** File description:
** update the player stats form his equipped items
*/
#include "../../include/myrpg.h"

void update_player_stats(player_t *player)
{
    int armor = 0;
    int attack = 0;

    if (player->inventory->equipped[0] != NULL)
        attack = player->inventory->equipped[0]->strength;
    for (int i = 1; i < 5; i++) {
        if (player->inventory->equipped[i] != NULL)
            armor += player->inventory->equipped[i]->strength;
    }
    player->item_armor = armor;
    player->axe_attack = attack;
    return;
}
