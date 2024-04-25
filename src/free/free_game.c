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
    sfRenderWindow_destroy(game_info->window);
    free(game_info->window_size_list);
    free(game_info);
    return;
}
