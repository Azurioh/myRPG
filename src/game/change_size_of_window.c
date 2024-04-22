/*
** EPITECH PROJECT, 2024
** change_size_of_window.c
** File description:
** Change the size of the actual window
*/

#include "../../include/myrpg.h"

int increase_size_of_window(game_t *game_info)
{
    if (!game_info
        || !game_info->window
        || !game_info->window_size_list) {
        return -1;
    }
    if (game_info->actual_window_size == 2) {
        return 0;
    }
    game_info->actual_window_size++;
    init_window(game_info);
    return 0;
}

int decrease_size_of_window(game_t *game_info)
{
    if (!game_info
        || !game_info->window
        || !game_info->window_size_list) {
        return -1;
    }
    if (game_info->actual_window_size == 0) {
        return 0;
    }
    game_info->actual_window_size--;
    init_window(game_info);
    return 0;
}
