/*
** EPITECH PROJECT, 2024
** move_menu
** File description:
** Move the menu function
*/

#include "../../include/myrpg.h"

void move_menu(game_menu_t *game_menu, sfVector2f offset)
{
    sfSprite_move(game_menu->background[0], offset);
    sfSprite_move(game_menu->background[1], offset);
    for (int i = 0; game_menu->buttons[i]; i++) {
        sfSprite_move(game_menu->buttons[i]->image_sprite, offset);
        game_menu->buttons[i]->position.x += offset.x;
        game_menu->buttons[i]->position.y += offset.y;
    }
    for (int i = 0; game_menu->texts[i]; i++) {
        sfText_move(game_menu->texts[i], offset);
    }
}
