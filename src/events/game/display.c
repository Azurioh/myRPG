/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** The function to display the game elements
*/

#include "../../../include/myrpg.h"

static void make_move(myrpg_t *myrpg)
{
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_down))
        move_down_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_up))
        move_up_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_right))
        move_right_view(myrpg->game_info, myrpg);
    if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->move_left))
        move_left_view(myrpg->game_info, myrpg);
}

static void display_menu(myrpg_t *myrpg)
{
    if (GAME_INFO->show_menu == 1)
        update_dynamic_texts(GAME_INFO, GAME_INFO->game_menu->texts);
    sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->background[0], NULL);
    sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->background[1], NULL);
    for (int i = 0; GAME_INFO->game_menu->buttons[i]; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
            GAME_INFO->game_menu->buttons[i]->image_sprite, NULL);
    }
    for (int i = 0; GAME_INFO->game_menu->texts[i]; i++) {
        sfRenderWindow_drawText(SETTINGS->window,
            GAME_INFO->game_menu->texts[i], NULL);
    }
}

void display_game(void *args)
{
    myrpg_t *myrpg = args;

    sfRenderWindow_setView(WINDOW, GAME_INFO->map_view);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->map, NULL);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->player, NULL);
    display_hud(myrpg);
    if (myrpg->is_inventory == 1)
        display_inventory(myrpg);
    if (GAME_INFO->show_menu >= 1)
        display_menu(myrpg);
    if (myrpg->is_inventory == 0 && GAME_INFO->show_menu == 0) {
        make_move(myrpg);
        move(myrpg);
    }
    GAME_INFO->keybinds->skills = sfKeyO;
    sfClock_restart(PLAYER_INTERFACE->clock);
}
