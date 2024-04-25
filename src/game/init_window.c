/*
** EPITECH PROJECT, 2024
** init_window.c
** File description:
** Function to init the game window
*/

#include "../../include/myrpg.h"

int init_window(game_t *game_info)
{
    sfRenderWindow *window;
    sfVideoMode window_size;

    if (!game_info || !game_info->window_size_list) {
        return -1;
    }
    window_size = game_info->window_size_list[game_info->actual_window_size];
    window = sfRenderWindow_create(window_size, "MyRPG", sfDefaultStyle, NULL);
    game_info->window = window;
    return 0;
}
