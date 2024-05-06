/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** The function to display the game elements
*/

#include "../../../include/myrpg.h"

static void make_move(myrpg_t *myrpg)
{
    if (sfKeyboard_isKeyPressed(MOVE_DOWN))
        move_down_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(MOVE_UP))
        move_up_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(MOVE_RIGHT))
        move_right_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(MOVE_LEFT))
        move_left_view(myrpg->game_info, myrpg);
}

void display_game(void *args)
{
    myrpg_t *myrpg = args;

    sfRenderWindow_setView(WINDOW, GAME_INFO->map_view);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->map, NULL);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->player, NULL);
    display_hud(myrpg);
    display_inventory(myrpg);
    if (myrpg->is_inventory == 0) {
        make_move(myrpg);
        move(myrpg);
    }
}
