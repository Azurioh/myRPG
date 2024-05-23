/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** set_all
*/

#include "../../include/myrpg.h"

static void set_hud(myrpg_t *myrpg, hud_t *hud)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f r = {center.x - size.x / 2, center.y - size.y / 2};

    sfSprite_setPosition(hud->exp->sprite, (sfVector2f){90 + r.x, 60 + r.y});
    sfSprite_setPosition(hud->life->sprite, (sfVector2f){90 + r.x, 36 + r.y});
    sfSprite_setPosition(hud->skill->sprite, (sfVector2f)
        {700 + r.x, 15 + r.y});
    sfSprite_setPosition(hud->profile->sprite, (sfVector2f){4 + r.x, 4 + r.y});
    sfSprite_setPosition(hud->inventory->sprite, (sfVector2f){1180 + r.x,
        350 + r.y});
    sfText_setPosition(hud->name, (sfVector2f){90 + r.x, 3 + r.y});
    sfText_setPosition(hud->action, (sfVector2f){1050 + r.x, 450 + r.y});
    sfText_setPosition(hud->act_text, (sfVector2f){1195 + r.x, 410 + r.y});
    sfText_setPosition(hud->skill_text, (sfVector2f){750 + r.x, 31 + r.y});
}

static void set_buttons_inv(myrpg_t *myrpg, button_t **buttons)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};
    sfVector2f position;
    int index = 0;

    for (int line = 0; line < 3; line++)
        for (int col = 0; col < 5; col++) {
            position = (sfVector2f){resize.x + 529.5 + col * 51.5,
                resize.y + 265 + line * 51.5};
            sfSprite_setPosition(buttons[index]->image_sprite, position);
            index += 1;
        }
    return;
}

static void set_inventory(inventory_t *inventory, myrpg_t *myrpg)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f r = {center.x - size.x / 2, center.y - size.y / 2};

    sfSprite_setPosition(inventory->image->sprite, (sfVector2f)
        {480 + r.x, 120 + r.y});
    for (int i = 0; inventory->buttons[i] != NULL; i++) {
        sfSprite_setPosition(inventory->buttons[i]->image_sprite, r);
        inventory->buttons[i]->position.x = r.x;
        inventory->buttons[i]->position.y = r.y;
    }
    sfText_setPosition(inventory->description,
        (sfVector2f){510 + r.x, 478 + r.y});
    sfText_setPosition(inventory->name, (sfVector2f){510 + r.x, 421 + r.y});
    for (int i = 0; inventory->equipped_sprite[i] != NULL; i++) {
        sfSprite_setPosition(inventory->equipped_sprite[i], r);
    }
    set_buttons_inv(myrpg, inventory->buttons);
    return;
}

static void set_menu(game_menu_t *game_menu, sfVector2f offset)
{
    sfSprite_move(game_menu->background[0], offset);
    sfSprite_move(game_menu->background[1], offset);
    for (int i = 0; game_menu->buttons[i]; i++) {
        sfSprite_setPosition(game_menu->buttons[i]->image_sprite, offset);
        game_menu->buttons[i]->position.x += offset.x;
        game_menu->buttons[i]->position.y += offset.y;
    }
}

void set_all_after_tp(myrpg_t *myrpg, sfVector2f movement)
{
    sfTime wait_time;

    wait_time.microseconds = 150000;
    sfView_setCenter(myrpg->game_info->map_view, movement);
    sfSprite_setPosition(myrpg->game_info->player, movement);
    set_hud(myrpg, myrpg->hud);
    set_inventory(myrpg->player->inventory, myrpg);
    set_menu(GAME_INFO->game_menu, movement);
    myrpg->player->pos.x = movement.x;
    myrpg->player->pos.y = movement.y;
    myrpg->player->interface->movement = (sfVector2f){0, 0};
    sfSprite_setPosition(myrpg->game_info->player, movement);
    sfSleep(wait_time);
}

void move_all_after_tp(myrpg_t *myrpg, sfVector2f tunnel_pos)
{
    sfTime wait_time;
    sfVector2f movement = {
        tunnel_pos.x - PLAYER->pos.x, tunnel_pos.y - PLAYER->pos.y};

    wait_time.microseconds = 150000;
    sfView_move(myrpg->game_info->map_view, movement);
    sfSprite_move(myrpg->game_info->player, movement);
    move_hud(myrpg->hud, movement);
    move_inventory(myrpg->player->inventory, movement);
    move_menu(GAME_INFO->game_menu, movement);
    myrpg->player->pos.x += movement.x;
    myrpg->player->pos.y += movement.y;
    sfSleep(wait_time);
}
