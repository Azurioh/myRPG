/*
** EPITECH PROJECT, 2024
** init_button
** File description:
** Function to init a button_t struct
*/

#include "../../include/myrpg.h"

button_t *init_button(char *button_name, sfVector2f position,
    char *image_path, void (*action)(void *))
{
    button_t *button = malloc(sizeof(button_t));

    if (!button) {
        return NULL;
    }
    button->button_name = strdup(button_name);
    button->position = position;
    button->image_sprite = generate_sprite_with_file(image_path);
    sfSprite_setPosition(button->image_sprite, button->position);
    button->actually_hover = sfFalse;
    button->actually_clicked = sfFalse;
    button->is_clicked = NULL;
    button->is_hover = NULL;
    button->action = action;
    return button;
}
