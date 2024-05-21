/*
** EPITECH PROJECT, 2024
** drop_item
** File description:
** drop an item
*/
#include "../../include/myrpg.h"

void drop_item(button_t *button, void *args)
{
    myrpg_t *myrpg = (myrpg_t *)args;
    button_t *selected_button = myrpg->player->inventory->selected_slot;
    int slot = 0;

    if (selected_button == NULL)
        return;
    slot = atoi(selected_button->button_name);
    (void)button;
    myrpg->player->inventory->selected_item = NULL;
    myrpg->player->inventory->selected_slot = NULL;
    myrpg->player->inventory->id[slot] = -1;
    return;
}
