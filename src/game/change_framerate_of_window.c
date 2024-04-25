/*
** EPITECH PROJECT, 2024
** change_framerate_of_window
** File description:
** Function to change the framerate for the game window
*/

#include "../../include/myrpg.h"
#include "SFML/Graphics/RenderWindow.h"

int decrease_framerate_of_window(game_t *game_info)
{
    if (!game_info || !game_info->framerate_list) {
        return -1;
    }
    if (game_info->actual_framerate == 0) {
        return 0;
    }
    game_info->actual_framerate--;
    sfRenderWindow_setFramerateLimit(game_info->window,
        game_info->framerate_list[game_info->actual_framerate]);
    return 0;
}

int increase_framerate_of_window(game_t *game_info)
{
    if (!game_info || !game_info->framerate_list) {
        return -1;
    }
    if (game_info->actual_framerate == 7) {
        return 0;
    }
    game_info->actual_framerate++;
    sfRenderWindow_setFramerateLimit(game_info->window,
        game_info->framerate_list[game_info->actual_framerate]);
    return 0;
}
