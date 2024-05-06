/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** Function to display the main menu
*/

#include "../../../include/myrpg.h"

void display_main_menu(void *args)
{
    myrpg_t *myrpg = args;
    sfRenderWindow *window = myrpg->settings->window;

    sfRenderWindow_drawSprite(window, myrpg->background, NULL);
    if (SETTINGS->show_settings_menu == 1) {
        return;
    }
    for (int i = 0; myrpg->buttons[i]; i++) {
        sfRenderWindow_drawSprite(window, myrpg->buttons[i]->image_sprite,
            NULL);
    }
}
