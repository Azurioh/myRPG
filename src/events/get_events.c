/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** get the events in the game
*/

#include "../../include/move.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

int check_events(game_t *game_info)
{
    if (game_info->event.type == sfEvtClosed)
        return -1;
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_DOWN)
        move_down_view(game_info);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_UP)
        move_up_view(game_info);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_RIGHT)
        move_right_view(game_info);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_LEFT)
        move_left_view(game_info);
    return 0;
}
