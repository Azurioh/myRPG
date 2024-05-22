/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

void check_coll_enemy(myrpg_t *myrpg)
{
    sfFloatRect rect_enemy = sfRectangleShape_getGlobalBounds(
    myrpg->mobs[0]->hitbox);
    sfFloatRect rect_player = sfRectangleShape_getGlobalBounds(myrpg->hitbox);

    if (sfFloatRect_intersects(&rect_player, &rect_enemy, NULL) == sfTrue &&
    myrpg->mobs[0]->can_collide == 1) {
        fight(myrpg);
        myrpg->mobs[0]->can_collide = 0;
    }
}

void game_loop(myrpg_t *myrpg)
{
    settings_t *settings = myrpg->settings;

    while (sfRenderWindow_pollEvent(settings->window,
        &EVENTS->event)) {
        if (EVENTS->event.type == sfEvtClosed) {
            myrpg->game_open = 0;
        }
        EVENTS->event_function(myrpg);
        check_coll_enemy(myrpg);
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
    save_game(myrpg);
    free_myrpg(myrpg);
    return 0;
}
