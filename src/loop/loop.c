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

void make_move(myrpg_t *myrpg)
{
    if (myrpg->fight_infos->in_fight == 0){
        if (sfKeyboard_isKeyPressed(MOVE_DOWN))
            move_down_view(myrpg->game_info, myrpg);
        if (sfKeyboard_isKeyPressed(MOVE_UP))
            move_up_view(myrpg->game_info, myrpg);
        if (sfKeyboard_isKeyPressed(MOVE_RIGHT))
            move_right_view(myrpg->game_info, myrpg);
        if (sfKeyboard_isKeyPressed(MOVE_LEFT))
            move_left_view(myrpg->game_info, myrpg);
    }
}

int game_loop(myrpg_t *myrpg)
{
    game_t *game_info = myrpg->game_info;

    while (sfRenderWindow_pollEvent(game_info->window,
        &game_info->event)) {
        if (check_events(myrpg) == -1) {
            return -1;
        }
    }
    make_move(myrpg);
    move(myrpg);
    display_main_menu(myrpg);
    check_fight(myrpg->fight_infos, myrpg->game_info);
    fight(myrpg);
    sfRenderWindow_clear(game_info->window, sfWhite);
    sfRenderWindow_setView(game_info->window, game_info->map_view);
    sfRenderWindow_drawSprite(game_info->window, game_info->map, NULL);
    sfRenderWindow_drawSprite(game_info->window, game_info->player, NULL);
    display_hud(myrpg);
    display_inventory(myrpg);
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
