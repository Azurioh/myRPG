/*
** EPITECH PROJECT, 2024
** manage_button_event.c
** File description:
** Function to manage the button's event
*/

#include "../../include/myrpg.h"

void manage_button_event(button_t **buttons, myrpg_t *myrpg)
{
    if (!buttons) {
        return;
    }
    for (int i = 0; buttons[i]; i++) {
        if (EVENTS->event.type == sfEvtMouseButtonPressed
            && buttons[i]->is_clicked(buttons[i], SETTINGS->window) == sfTrue
            && buttons[i]->action) {
            buttons[i]->action(buttons[i], myrpg);
            return;
        }
        if (EVENTS->event.type == sfEvtMouseMoved) {
            buttons[i]->is_hover(buttons[i], SETTINGS->window);
        }
        animate_button(buttons[i]);
    }
}
