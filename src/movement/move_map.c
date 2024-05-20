/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** move the view
*/

#include "../../include/myrpg.h"

void move_down_view(game_t *game_info, myrpg_t *myrpg)
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
    myrpg->player->interface->movement.y += myrpg->player->interface->speed;
}

void move_up_view(game_t *game_info, myrpg_t *myrpg)
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
    myrpg->player->interface->movement.y -= myrpg->player->interface->speed;
}

void move_left_view(game_t *game_info, myrpg_t *myrpg)
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
    myrpg->player->interface->movement.x -= myrpg->player->interface->speed;
}

void move_right_view(game_t *game_info, myrpg_t *myrpg)
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
    myrpg->player->interface->movement.x += myrpg->player->interface->speed;
}

void move(myrpg_t *myrpg)
{
    sfVector2f movement = myrpg->player->interface->movement;

    sfView_move(myrpg->game_info->map_view, movement);
    sfSprite_move(myrpg->game_info->player, movement);
    move_hud(myrpg->hud, movement);
    move_inventory(myrpg->player->inventory, movement);
    myrpg->player->interface->movement = (sfVector2f){0, 0};
    sfSprite_getPosition(myrpg->game_info->player);
}
