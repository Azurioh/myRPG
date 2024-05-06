/*
** EPITECH PROJECT, 2024
** unload.c
** File description:
** Function for unload the main menu
*/

#include "../../../include/myrpg.h"

void unload_main_menu(void *args)
{
    myrpg_t *myrpg = args;

    sfSprite_destroy(myrpg->background);
    for (int i = 0; BUTTONS[i]; i++) {
        free_button(BUTTONS[i]);
    }
    BUTTONS = NULL;
}
