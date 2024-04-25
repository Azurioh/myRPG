/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** move the view
*/

#include "../../include/game.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

void move_down_view(game_t *game_info)
{
    sfVector2f center_view;

    sfView_move(game_info->map_view, (sfVector2f){0, 7});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_up_view(game_t *game_info)
{
    sfVector2f center_view;

    sfView_move(game_info->map_view, (sfVector2f){0, -7});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_left_view(game_t *game_info)
{
    sfVector2f center_view;

    sfView_move(game_info->map_view, (sfVector2f){-7, 0});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_right_view(game_t *game_info)
{
    sfVector2f center_view;

    sfView_move(game_info->map_view, (sfVector2f){7, 0});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}
