/*
** EPITECH PROJECT, 2024
** make_transition
** File description:
** make a transition between two scenes
*/
#include "../../include/myrpg.h"

void zoom_view(myrpg_t *myrpg, sfClock *clock)
{
    if (GAME_INFO->transition_state == 1) {
        sfView_zoom(GAME_INFO->map_view, 0.8);
        if (sfView_getSize(GAME_INFO->map_view).y <= 10) {
            GAME_INFO->transition_state = 2;
        }
    }
    if (GAME_INFO->transition_state == 2) {
        sfView_zoom(GAME_INFO->map_view, 1.2);
        if (sfView_getSize(GAME_INFO->map_view).y >= 702)
            GAME_INFO->transition_state = 3;
    }
    sfClock_restart(clock);
}

int make_transition(myrpg_t *myrpg)
{
    static sfClock *clock;
    sfTime elapsed;

    if (GAME_INFO->transition_state == 3)
        return 1;
    if (GAME_INFO->transition_state == 0) {
        clock = sfClock_create();
        GAME_INFO->transition_state = 1;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 0.01) {
        zoom_view(myrpg, clock);
    }
    if (GAME_INFO->transition_state == 3) {
        sfView_setSize(GAME_INFO->map_view, (sfVector2f){1248, 702});
    }
    return 0;
}
