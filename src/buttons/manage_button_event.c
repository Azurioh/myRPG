/*
** EPITECH PROJECT, 2024
** manage_button_event.c
** File description:
** Function to manage the button's event
*/

#include "../../include/myrpg.h"

static bool is_mouse_event(sfEvent event)
{
    switch (event.type) {
        case sfEvtMouseButtonPressed:
            return true;
        case sfEvtMouseButtonReleased:
            return true;
        case sfEvtMouseMoved:
            return true;
        default:
            return false;
    }
    return false;
}

void manage_button_event(button_t **buttons, myrpg_t *myrpg)
{
    if (!buttons) {
        return;
    }
    if (is_mouse_event(EVENTS->event) == false)
        return;
    for (int i = 0; buttons[i]; i++) {
        if (buttons[i]->clickable == sfFalse)
            continue;
        buttons[i]->is_hover(buttons[i], SETTINGS->window);
        if (EVENTS->event.type == sfEvtMouseButtonPressed
            && buttons[i]->is_clicked(buttons[i], SETTINGS->window) == sfTrue
            && buttons[i]->action) {
            buttons[i]->action(buttons[i], myrpg);
            return;
        }
        if (EVENTS->event.type == sfEvtMouseButtonReleased) {
            buttons[i]->release(buttons[i]);
        }
        animate_button(buttons[i]);
    }
}
