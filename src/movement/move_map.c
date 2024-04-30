/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** move the view
*/

#include "../../include/game.h"

void move_down_view(game_t *game_info)
{
    sfVector2f center_view;
    sfColor color;
    const sfFloatRect rect = sfSprite_getGlobalBounds(game_info->player);

    center_view = sfView_getCenter(game_info->map_view);
    color = sfImage_getPixel(game_info->undermap, center_view.x,
                    center_view.y + rect.height);
    if (color.r == 255 && color.g == 0 && color.b == 0 &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return;
    }
    sfView_move(game_info->map_view, (sfVector2f){0, 7});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_up_view(game_t *game_info)
{
    sfVector2f center_view;
    sfColor color;
    const sfFloatRect rect = sfSprite_getGlobalBounds(game_info->player);

    center_view = sfView_getCenter(game_info->map_view);
    color = sfImage_getPixel(game_info->undermap, center_view.x,
                    center_view.y);
    if (color.r == 255 && color.g == 0 && color.b == 0 &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return;
    }
    sfView_move(game_info->map_view, (sfVector2f){0, -7});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_left_view(game_t *game_info)
{
    sfVector2f center_view;
    sfColor color;
    const sfFloatRect rect = sfSprite_getGlobalBounds(game_info->player);

    center_view = sfView_getCenter(game_info->map_view);
    color = sfImage_getPixel(game_info->undermap, center_view.x,
                    center_view.y);
    if (color.r == 255 && color.g == 0 && color.b == 0 &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return;
    }
    sfView_move(game_info->map_view, (sfVector2f){-7, 0});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}

void move_right_view(game_t *game_info)
{
    sfVector2f center_view;
    sfColor color;
    const sfFloatRect rect = sfSprite_getGlobalBounds(game_info->player);

    center_view = sfView_getCenter(game_info->map_view);
    color = sfImage_getPixel(game_info->undermap, center_view.x + rect.width,
                    center_view.y);
    if (color.r == 255 && color.g == 0 && color.b == 0 &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return;
    }
    sfView_move(game_info->map_view, (sfVector2f){7, 0});
    center_view = sfView_getCenter(game_info->map_view);
    sfSprite_setPosition(game_info->player, center_view);
}
