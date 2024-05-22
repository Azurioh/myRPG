/*
** EPITECH PROJECT, 2024
** free_game.c
** File description:
** Function to free the game struct
*/

#include "../../include/myrpg.h"

static void free_game_menu(game_menu_t *game_menu)
{
    if (!game_menu) {
        return;
    }
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(game_menu->background[i]);
    }
    for (int i = 0; game_menu->buttons[i]; i++) {
        free_button(game_menu->buttons[i]);
    }
    for (int i = 0; game_menu->texts[i]; i++) {
        sfText_destroy(game_menu->texts[i]);
    }
    free(game_menu->background);
    free(game_menu->buttons);
    free(game_menu->texts);
    free(game_menu);
}

static void free_keybinds(keybinds_t *keybinds)
{
    if (keybinds->actions)
        free(keybinds->actions);
    if (keybinds->keybind_edit)
        free(keybinds->keybind_edit);
    free(keybinds);
}

void free_game(game_t *game_info)
{
    if (!game_info) {
        return;
    }
    if (!game_info->map_view) {
        free_keybinds(game_info->keybinds);
        return free(game_info);
    }
    sfSprite_destroy(game_info->map);
    sfImage_destroy(game_info->undermap);
    sfView_destroy(game_info->map_view);
    sfSprite_destroy(game_info->player);
    free_keybinds(game_info->keybinds);
    free_game_menu(game_info->game_menu);
    sfClock_destroy(game_info->clock);
    free(game_info);
    return;
}
