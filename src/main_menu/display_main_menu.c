/*
** EPITECH PROJECT, 2024
** display_main_menu.c
** File description:
** Function to display the main menu
*/

#include "../../include/myrpg.h"

void display_main_menu(myrpg_t *myrpg)
{
    sfRenderWindow *window = myrpg->game_info->window;

    sfRenderWindow_drawSprite(window, myrpg->background, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(window,
            myrpg->buttons[i]->image_sprite, NULL);
    }
    return;
}
