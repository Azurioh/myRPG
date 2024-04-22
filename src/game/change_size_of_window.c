/*
** EPITECH PROJECT, 2024
** change_size_of_window.c
** File description:
** Change the size of the actual window
*/

#include "../../include/myrpg.h"

int change_size_of_window(game_t *game_info, int add)
{
    if (!game_info
        || !game_info->window
        || !game_info->window_size_list
        || !game_info->actual_window_size)
        return -1;
    if (add == 0) {
        if (game_info->actual_window_size == 0)
            return 0;
        game_info->actual_window_size--;
    } else {
        if (game_info->actual_window_size == 1)
            return 0;
        game_info->actual_window_size++;
    }
    init_window(game_info);
    return 0;
}
