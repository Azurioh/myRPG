/*
** EPITECH PROJECT, 2024
** free_game.c
** File description:
** Function to free the game struct
*/

#include "../../include/myrpg.h"

void free_game(game_t *game_info)
{
    if (!game_info) {
        return;
    }
    free(game_info);
    return;
}
