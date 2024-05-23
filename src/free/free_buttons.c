/*
** EPITECH PROJECT, 2024
** free_button
** File description:
** Function to free a button_t struct
*/

#include "../../include/myrpg.h"

void free_button(button_t *button)
{
    if (!button) {
        return;
    }
    free(button->button_name);
    sfSprite_destroy(button->image_sprite);
    free(button);
    return;
}

void free_all_buttons(button_t **buttons)
{
    if (!buttons) {
        return;
    }
    for (int i = 0; buttons[i]; i++) {
        free_button(buttons[i]);
    }
    free(buttons);
}
