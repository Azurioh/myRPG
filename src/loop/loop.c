/*
** EPITECH PROJECT, 2024
** loop.c
** File description:
** The initial loop game
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window/Keyboard.h>
#include <time.h>
#include <unistd.h>

int game_loop(myrpg_t *myrpg)
{
    game_t *game_info = myrpg->game_info;

    while (sfRenderWindow_pollEvent(game_info->window,
        &game_info->event)) {
        if (check_events(game_info, myrpg->hud) == -1) {
            return -1;
        }
    }
    display_main_menu(myrpg);
    sfRenderWindow_clear(game_info->window, sfWhite);
    sfRenderWindow_clear(game_info->window, sfBlack);
    sfRenderWindow_drawSprite(game_info->window, game_info->map, NULL);
    sfRenderWindow_setView(game_info->window, game_info->map_view);
    display_hud(myrpg);
    display_inventory(myrpg);
    sfRenderWindow_drawSprite(game_info->window, game_info->player, NULL);
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
