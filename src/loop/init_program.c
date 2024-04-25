/*
** EPITECH PROJECT, 2024
** init_program.c
** File description:
** Function to init the program and start the game
*/

#include "../../include/myrpg.h"

static myrpg_t *init_myrpg(void)
{
    myrpg_t *myrpg = malloc(sizeof(myrpg_t));

    if (!myrpg) {
        return NULL;
    }
    myrpg->game_info = init_game_struct();
    myrpg->list_of_events = NULL;
    myrpg->background = NULL;
    myrpg->buttons = NULL;
    return myrpg;
}

int start_game(void)
{
    myrpg_t *myrpg = init_myrpg();

    if (!myrpg) {
        return 84;
    } else {
    return loop(myrpg);
    }
}
