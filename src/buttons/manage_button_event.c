/*
** EPITECH PROJECT, 2024
** manage_button_event.c
** File description:
** Function to manage the button's event
*/

#include "../../include/myrpg.h"

void manage_button_event(button_t **buttons, myrpg_t *myrpg)
{
    for (int i = 0; buttons[i]; i++) {
        if (GAME_INFO->event.type == sfEvtMouseButtonPressed
            && buttons[i]->is_hover(buttons[i], GAME_INFO->window) == sfTrue) {
            buttons[i]->action(buttons[i], myrpg);
        }
        if (GAME_INFO->event.type == sfEvtMouseMoved) {
            buttons[i]->is_hover(buttons[i], GAME_INFO->window);
        }
        animate_button(buttons[i], myrpg->settings);
    }
}
