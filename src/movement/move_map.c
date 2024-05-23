/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** move the view
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>

static void animate_player(myrpg_t *myrpg, int top)
{
    float seconds = get_time(myrpg->game_info->clock);
    static int offset = 0;
    float animation_time = 0.1;

    if (PLAYER->sprinting == true)
        animation_time = 0.05;
    if (seconds > animation_time) {
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
    sfVector2f pos = sfSprite_getPosition(GAME_INFO->player);
    sfColor color;

    pos.x += 16 * 1.5;
    pos.y += 64 * 1.5 + 4;
    color = sfImage_getPixel(game_info->undermap, pos.x,
                    pos.y);
    if (color.r == 255 && color.g == 0 && color.b == 0){
        return;
    }
    animate_player(myrpg, 0);
    myrpg->player->interface->movement.y += myrpg->player->interface->speed;
}

void move_up_view(game_t *game_info, myrpg_t *myrpg)
{
    sfVector2f pos = sfSprite_getPosition(GAME_INFO->player);
    sfColor color;

    pos.x += 16 * 1.5;
    pos.y += 64 * 1.5 - 18;
    color = sfImage_getPixel(game_info->undermap, pos.x,
                    pos.y);
    if (color.r == 255 && color.g == 0 && color.b == 0){
        return;
    }
    animate_player(myrpg, 3);
    myrpg->player->interface->movement.y -= myrpg->player->interface->speed;
}

void move_left_view(game_t *game_info, myrpg_t *myrpg)
{
    sfVector2f pos = sfSprite_getPosition(GAME_INFO->player);
    sfColor color;

    pos.x += 14 * 1.5 - 4;
    pos.y += 64 * 1.5;
    color = sfImage_getPixel(game_info->undermap, pos.x,
                    pos.y);
    if (color.r == 255 && color.g == 0 && color.b == 0){
        return;
    }
    animate_player(myrpg, 1);
    myrpg->player->interface->movement.x -= myrpg->player->interface->speed;
}

void move_right_view(game_t *game_info, myrpg_t *myrpg)
{
    sfVector2f pos = sfSprite_getPosition(GAME_INFO->player);
    sfColor color;

    pos.x += 16 * 1.5 + 4;
    pos.y += 64 * 1.5;
    color = sfImage_getPixel(game_info->undermap, pos.x,
                    pos.y);
    if (color.r == 255 && color.g == 0 && color.b == 0){
        return;
    }
    animate_player(myrpg, 2);
    myrpg->player->interface->movement.x += myrpg->player->interface->speed;
}

void move(myrpg_t *myrpg)
{
    float seconds = get_time(PLAYER_INTERFACE->clock);
    sfVector2f movement = myrpg->player->interface->movement;

    movement.x *= seconds;
    movement.y *= seconds;
    if (PLAYER->sprinting == true) {
        movement.x *= 2;
        movement.y *= 2;
    }
    sfView_move(myrpg->game_info->map_view, movement);
    sfSprite_move(myrpg->game_info->player, movement);
    move_hud(myrpg->hud, movement);
    move_inventory(myrpg->player->inventory, movement);
    move_menu(GAME_INFO->game_menu, movement);
    myrpg->player->pos.x += movement.x;
    myrpg->player->pos.y += movement.y;
    myrpg->player->interface->movement = (sfVector2f){0, 0};
    sfRectangleShape_setPosition(myrpg->hitbox,
    sfSprite_getPosition(myrpg->game_info->player));
    sfClock_restart(PLAYER_INTERFACE->clock);
}
