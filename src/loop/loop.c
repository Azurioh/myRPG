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

static void fade_background(myrpg_t *myrpg)
{
    sfColor bg_color =
        sfRectangleShape_getFillColor(myrpg->loading_screen->background);
    sfTime time;

    while (bg_color.a > 0) {
        time = sfClock_getElapsedTime(myrpg->loading_screen->animation_clock);
        if (time.microseconds >= 1000) {
            bg_color.a -= 2.55;
            sfRectangleShape_setFillColor(myrpg->loading_screen->background,
                bg_color);
            sfClock_restart(myrpg->loading_screen->animation_clock);
        }
        sfRenderWindow_clear(WINDOW, sfWhite);
        EVENTS->display_function(myrpg);
        sfRenderWindow_drawRectangleShape(WINDOW,
            myrpg->loading_screen->background, NULL);
        sfRenderWindow_display(WINDOW);
    }
}

int loop(myrpg_t *myrpg)
{
    EVENTS->load_function(myrpg);
    fade_background(myrpg);
    while (myrpg->game_open == 1) {
        game_loop(myrpg);
    }
    free_mobs(myrpg->mobs);
    free_myrpg(myrpg);
    return 0;
}
