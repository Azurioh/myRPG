/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** get the events in the game
*/

#include "../../include/move.h"
#include "../../include/hud.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void make_move(game_t *game_info, hud_t *hud)
{
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_DOWN)
        move_down_view(game_info, hud);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_UP)
        move_up_view(game_info, hud);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_RIGHT)
        move_right_view(game_info, hud);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_LEFT)
        move_left_view(game_info, hud);
}

int check_events(game_t *game_info, hud_t *hud)
{
    if (game_info->event.type == sfEvtClosed)
        return -1;
    make_move(game_info, hud);
    return 0;
}
