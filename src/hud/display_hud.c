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

char *name_and_level(myrpg_t *myrpg)
{
    char *player = strdup("");

    strcat(player, myrpg->player->name);
    strcat(player, " Lvl.");
    strcat(player, nbr_to_str(myrpg->player->level));
    return player;
}

void display_hud(myrpg_t *myrpg)
{
    sfRenderWindow *window = myrpg->game_info->window;

    myrpg->player->experience = 50;
    myrpg->player->life = 90;
    myrpg->player->level = 69;
    sfRenderWindow_drawSprite(window, myrpg->hud->profile->sprite, NULL);
    change_percentage(myrpg->hud->life->sprite, myrpg->player->life);
    change_percentage(myrpg->hud->exp->sprite, myrpg->player->experience);
    sfRenderWindow_drawSprite(window, myrpg->hud->life->sprite, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->exp->sprite, NULL);
    sfText_setString(myrpg->hud->name, name_and_level(myrpg));
    sfRenderWindow_drawText(window, myrpg->hud->name, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->inventory->sprite, NULL);
    sfRenderWindow_drawSprite(window, myrpg->hud->action->sprite, NULL);
    sfRenderWindow_drawText(window, myrpg->hud->act_text, NULL);
}
