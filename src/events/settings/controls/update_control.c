/*
** EPITECH PROJECT, 2024
** update_control.c
** File description:
** Function to update the keybinds
*/

#include "../../../../include/myrpg.h"

void update_controls(myrpg_t *myrpg)
{
    GAME_INFO->keybinds->move_up = GAME_INFO->keybinds->keybind_edit[0];
    GAME_INFO->keybinds->move_down = GAME_INFO->keybinds->keybind_edit[1];
    GAME_INFO->keybinds->move_left = GAME_INFO->keybinds->keybind_edit[2];
    GAME_INFO->keybinds->move_right = GAME_INFO->keybinds->keybind_edit[3];
    GAME_INFO->keybinds->open_inventory = GAME_INFO->keybinds->keybind_edit[4];
    GAME_INFO->keybinds->interact = GAME_INFO->keybinds->keybind_edit[5];
    GAME_INFO->keybinds->skills = GAME_INFO->keybinds->keybind_edit[6];
    GAME_INFO->keybinds->editing_keybinds = sfFalse;
    EVENTS->event_function = &exec_settings_events;
    EVENTS->load_function(myrpg);
}
