/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** move the view
*/

#include "../../include/myrpg.h"

static void animate_player(myrpg_t *myrpg, int top)
{
    float seconds = get_time(myrpg->game_info->clock);
    static int offset = 0;

    if (seconds > 0.1) {
        PLAYER_INTERFACE->rect.top = PLAYER_INTERFACE->rect.height * top;
        PLAYER_INTERFACE->rect.left = offset * PLAYER_INTERFACE->rect.width;
        sfClock_restart(myrpg->game_info->clock);
        offset += 1;
        if (offset == 4)
            offset = 0;
        sfSprite_setTextureRect(GAME_INFO->player, PLAYER_INTERFACE->rect);
    }
}

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
    animate_player(myrpg, 0);
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
    animate_player(myrpg, 3);
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
    animate_player(myrpg, 1);
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
    animate_player(myrpg, 2);
    myrpg->player->interface->movement.x += myrpg->player->interface->speed;
}

static void move_menu(game_menu_t *game_menu, sfVector2f offset)
{
    sfSprite_move(game_menu->background, offset);
    for (int i = 0; game_menu->buttons[i]; i++) {
        sfSprite_move(game_menu->buttons[i]->image_sprite, offset);
        game_menu->buttons[i]->position.x += offset.x;
        game_menu->buttons[i]->position.y += offset.y;
    }
}

void move(myrpg_t *myrpg)
{
    float seconds = get_time(PLAYER_INTERFACE->clock);
    sfVector2f movement = myrpg->player->interface->movement;

    movement.x *= seconds;
    movement.y *= seconds;
    sfView_move(myrpg->game_info->map_view, movement);
    sfSprite_move(myrpg->game_info->player, movement);
    move_hud(myrpg->hud, movement);
    move_inventory(myrpg->player->inventory, movement);
    move_menu(GAME_INFO->game_menu, movement);
    myrpg->player->pos.x += movement.x;
    myrpg->player->pos.y += movement.y;
    myrpg->player->interface->movement = (sfVector2f){0, 0};
    sfSprite_getPosition(myrpg->game_info->player);
    sfClock_restart(PLAYER_INTERFACE->clock);
}
