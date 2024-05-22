/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** set_all
*/

#include "../../include/myrpg.h"

static void set_hud(hud_t *hud, sfVector2f offset)
{
    sfSprite_setPosition(hud->exp->sprite, offset);
    sfSprite_setPosition(hud->life->sprite, offset);
    sfSprite_setPosition(hud->skill->sprite, offset);
    sfSprite_setPosition(hud->profile->sprite, offset);
    sfSprite_setPosition(hud->inventory->sprite, offset);
    sfText_setPosition(hud->name, offset);
    sfText_setPosition(hud->action, offset);
    sfText_setPosition(hud->act_text, offset);
    sfText_setPosition(hud->skill_text, offset);
}

static void set_inventory(inventory_t *inventory, sfVector2f offset)
{
    sfSprite_setPosition(inventory->image->sprite, offset);
    for (int i = 0; inventory->buttons[i] != NULL; i++) {
        sfSprite_setPosition(inventory->buttons[i]->image_sprite, offset);
        inventory->buttons[i]->position.x += offset.x;
        inventory->buttons[i]->position.y += offset.y;
    }
    sfText_setPosition(inventory->description, offset);
    sfText_setPosition(inventory->name, offset);
    for (int i = 0; inventory->equipped_sprite[i] != NULL; i++)
        sfSprite_setPosition(inventory->equipped_sprite[i], offset);
    for (int i = 0; inventory->action_buttons[i] != NULL; i++)
        sfSprite_setPosition(inventory->action_buttons[i]->image_sprite,
            offset);
    return;
}

static void set_menu(game_menu_t *game_menu, sfVector2f offset)
{
    sfSprite_setPosition(game_menu->background, offset);
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
    set_hud(myrpg->hud, movement);
    set_inventory(myrpg->player->inventory, movement);
    set_menu(GAME_INFO->game_menu, movement);
    myrpg->player->pos.x = movement.x;
    myrpg->player->pos.y = movement.y;
    myrpg->player->interface->movement = (sfVector2f){0, 0};
    sfSprite_setPosition(myrpg->game_info->player, movement);
    sfSleep(wait_time);
}
