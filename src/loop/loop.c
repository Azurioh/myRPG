/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

void game_loop(myrpg_t *myrpg)
{
    settings_t *settings = myrpg->settings;

    while (sfRenderWindow_pollEvent(settings->window,
        &EVENTS->event)) {
        if (EVENTS->event.type == sfEvtClosed) {
            myrpg->game_open = 0;
        }
        EVENTS->event_function(myrpg);
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
            fight(myrpg);
        }
    }
    sfRenderWindow_clear(settings->window, sfBlack);
    EVENTS->display_function(myrpg);
    sfRenderWindow_display(settings->window);
}

int loop(myrpg_t *myrpg)
{
    EVENTS->load_function(myrpg);
    while (myrpg->game_open == 1) {
        game_loop(myrpg);
    }
    free_myrpg(myrpg);
    return 0;
}
