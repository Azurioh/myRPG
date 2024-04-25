/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"

int game_loop(myrpg_t *myrpg)
{
    game_t *game_info = myrpg->game_info;

    while (sfRenderWindow_pollEvent(game_info->window,
        &game_info->event)) {
        if (game_info->event.type == sfEvtClosed) {
            return -1;
        }
    }
    sfRenderWindow_clear(game_info->window, sfWhite);
    display_hud(myrpg);
    sfRenderWindow_clear(game_info->window, sfBlack);
    display_main_menu(myrpg);
    sfRenderWindow_display(game_info->window);
    return 0;
}

int loop(myrpg_t *myrpg)
{
    load_main_menu(myrpg);
    while (1) {
        if (game_loop(myrpg) == -1) {
            break;
        }
    }
    free_myrpg(myrpg);
    return 0;
}
