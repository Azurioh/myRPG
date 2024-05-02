/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** get the events in the game
*/
#include "../../include/myrpg.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void make_move(game_t *game_info, myrpg_t *myrpg)
{
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_DOWN)
        move_down_view(game_info, myrpg);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_UP)
        move_up_view(game_info, myrpg);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_RIGHT)
        move_right_view(game_info, myrpg);
    if (game_info->event.type == sfEvtKeyPressed &&
        game_info->event.key.code == MOVE_LEFT)
        move_left_view(game_info, myrpg);
}

int check_events(myrpg_t *myrpg)
{
    if (myrpg->game_info->event.type == sfEvtClosed)
        return -1;
    make_move(myrpg->game_info, myrpg);
    if (myrpg->game_info->event.type == sfEvtKeyPressed &&
        myrpg->game_info->event.key.code == INVENTORY_KEY)
        myrpg->is_inventory = (myrpg->is_inventory == 0) ? 1 : 0;
    return 0;
}
