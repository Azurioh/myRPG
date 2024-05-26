/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <math.h>

void game_loop(myrpg_t *myrpg)
{
    settings_t *settings = myrpg->settings;

    while (sfRenderWindow_pollEvent(settings->window,
        &EVENTS->event) && myrpg->transition_state == 3) {
        if (EVENTS->event.type == sfEvtClosed) {
            myrpg->game_open = 0;
            return;
        }
        EVENTS->event_function(myrpg);
    }
    sfRenderWindow_clear(settings->window, sfBlack);
    EVENTS->display_function(myrpg);
    update_quest(myrpg->quests);
    sfRenderWindow_display(settings->window);
    if (GAME_INFO->map_view)
        make_transition(myrpg);
}

int loop(myrpg_t *myrpg)
{
    EVENTS->load_function(myrpg);
    while (myrpg->game_open == 1) {
        game_loop(myrpg);
    }
    free_mobs(myrpg->mobs);
    free_myrpg(myrpg);
    return 0;
}
