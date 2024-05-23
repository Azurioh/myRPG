/*
** EPITECH PROJECT, 2024
** update_experience.c
** File description:
** Functions to update the experience of the player
*/

#include "../../include/myrpg.h"

int update_player_experience(player_t *player, unsigned int amount)
{
    if (!player) {
        return -1;
    }
    player->experience += amount;
    if (player->experience >= player->max_xp) {
        player->experience -= player->max_xp;
        player->max_hp += 10;
        player->attack += 5;
        player->armor += 2;
        player->level++;
        if (player->level <= 9)
            player->nb_skills_to_upgrade++;
    }
    return 0;
}
