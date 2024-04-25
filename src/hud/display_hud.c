/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"

void change_percentage(sfSprite *sprite, int percentage)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 104 * percentage / 100;
    rect.height = 12;
    sfSprite_setTextureRect(sprite, rect);
}

void display_hud(myrpg_t *myrpg)
{
    sfRenderWindow *window = myrpg->game_info->window;

    myrpg->player->experience = 75;
    myrpg->player->life = 69;
    sfRenderWindow_drawSprite(window, myrpg->hud->profile->sprite, NULL);
    change_percentage(myrpg->hud->life->sprite, myrpg->player->experience);
    change_percentage(myrpg->hud->level->sprite, myrpg->player->life);
    sfRenderWindow_drawSprite(window, myrpg->hud->life->sprite, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->level->sprite, NULL);
}
