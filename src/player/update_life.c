/*
** EPITECH PROJECT, 2024
** update_life.c
** File description:
** Functions to update the life of the player
*/

#include "../../include/myrpg.h"

int increase_player_life(player_t *player, unsigned int amount)
{
    if (!player) {
        return -1;
    }
    if (player->life == player->max_hp) {
        return 0;
    }
    player->life += amount;
    if (player->life > 100) {
        player->life = player->max_hp;
    }
    return 0;
}

int decrease_player_life(player_t *player, unsigned int amount)
{
    if (!player) {
        return -1;
    }
    if (player->life == 0) {
        return 0;
    }
    player->life -= amount;
    if (player->life <= 0) {
        player->is_alive = 0;
        player->nb_dead++;
    }
    return 0;
}
