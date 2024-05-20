/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** get the events in the game
*/
#include "../../include/myrpg.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

int check_events(myrpg_t *myrpg)
{
    if (myrpg->game_info->event.type == sfEvtClosed)
        return -1;
    if (myrpg->game_info->event.type == sfEvtKeyPressed &&
        myrpg->game_info->event.key.code == INVENTORY_KEY)
        myrpg->is_inventory = (myrpg->is_inventory == 0) ? 1 : 0;
    if (myrpg->game_info->event.type == sfEvtMouseButtonPressed)
        printf("x: %d, y: %d\n", myrpg->game_info->event.mouseButton.x, myrpg->game_info->event.mouseButton.y);
    return 0;
}
