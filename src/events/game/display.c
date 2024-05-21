/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** The function to display the game elements
*/

#include "../../../include/myrpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

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
    sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->background, NULL);
    for (int i = 0; GAME_INFO->game_menu->buttons[i]; i++) {
        sfRenderWindow_drawSprite(SETTINGS->window,
        GAME_INFO->game_menu->buttons[i]->image_sprite, NULL);
    }
}

void display_game(void *args)
{
    myrpg_t *myrpg = args;

    sfRenderWindow_setView(WINDOW, GAME_INFO->map_view);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->map, NULL);
    sfRenderWindow_drawSprite(WINDOW, GAME_INFO->player, NULL);
    display_hud(myrpg);
    if (myrpg->fight_infos->in_fight == 1) {
        fight(myrpg);
    }
    if (myrpg->is_inventory == 1)
        display_inventory(myrpg);
    if (GAME_INFO->show_menu == 1)
        display_menu(myrpg);
    if (myrpg->is_inventory == 0 && GAME_INFO->show_menu == 0 &&
        myrpg->fight_infos->in_fight == 0) {
        make_move(myrpg);
        move(myrpg);
    }
}
