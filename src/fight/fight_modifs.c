/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Fight modifications
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static void setup_rect_player(myrpg_t *myrpg)
{
    sfIntRect rect;

    myrpg->game_info->rect = sfSprite_getTextureRect(myrpg->game_info->player);
    rect.top = 128;
    rect.left = 0;
    rect.width = 32;
    rect.height = 192;
    sfSprite_setTextureRect(myrpg->game_info->player, rect);
}

static void setup_rect_mob(myrpg_t *myrpg, int i)
{
    sfIntRect rect;

    myrpg->mobs[i]->rect = sfSprite_getTextureRect(myrpg->mobs[i]->sprite);
    rect.top = 48;
    rect.left = 0;
    rect.width = 48;
    rect.height = 96;
    sfSprite_setTextureRect(myrpg->mobs[i]->sprite, rect);
}

static void setup_mob_life(myrpg_t *myrpg, sfVector2f resize)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/alagard.ttf");

    sfText_setFont(text, font);
    sfText_setString(text, "Enemy's Health");
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 2);
    myrpg->fight_infos->enemy_infos->string = text;
    sfText_setPosition(myrpg->fight_infos->enemy_infos->string,
        (sfVector2f){resize.x + 610, resize.y + 10});
    sfSprite_setPosition(myrpg->fight_infos->enemy_infos->enemy_life,
        (sfVector2f){resize.x + 636, resize.y + 56});
    sfSprite_setPosition(myrpg->fight_infos->enemy_infos->enemy_bottle,
        (sfVector2f){resize.x + 600, resize.y + 50});
    sfSprite_setScale(myrpg->fight_infos->enemy_infos->enemy_life,
        (sfVector2f){1.5, 1.5});
    sfSprite_setScale(myrpg->fight_infos->enemy_infos->enemy_bottle,
        (sfVector2f){1.5, 1.5});
}

void setup_sprites(myrpg_t *myrpg, sfVector2f resize, int i, int make)
{
    sfSprite_setPosition(myrpg->game_info->player, (sfVector2f){resize.x + 100,
        resize.y + 450});
    sfSprite_setPosition(myrpg->mobs[i]->sprite, (sfVector2f){resize.x + 1000,
        resize.y + 520});
    if (make == 0) {
        sfSprite_setScale(myrpg->game_info->player, (sfVector2f){4, 4});
        setup_rect_player(myrpg);
        setup_rect_mob(myrpg, i);
        setup_mob_life(myrpg, resize);
        sfSprite_setScale(myrpg->mobs[i]->sprite, (sfVector2f){4, 4});
    } else {
        sfSprite_setScale(myrpg->game_info->player, (sfVector2f){1.5, 1.5});
        sfSprite_setScale(myrpg->mobs[i]->sprite, (sfVector2f){2, 2});
    }
}

int tp_all(myrpg_t *myrpg, int i, int j)
{
    sfVector2f center = sfView_getCenter(myrpg->game_info->map_view);
    sfVector2f size = sfView_getSize(myrpg->game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    sfSprite_setPosition(myrpg->hud->profile->sprite,
        (sfVector2f){resize.x + 4, resize.y + 4});
    sfSprite_setPosition(myrpg->hud->exp->sprite,
        (sfVector2f){resize.x + 90, resize.y + 60});
    sfSprite_setPosition(myrpg->hud->life->sprite,
        (sfVector2f){resize.x + 90, resize.y + 36});
    sfText_setPosition(myrpg->hud->name, (sfVector2f){resize.x + 90,
        resize.y + 3});
    setup_sprites(myrpg, resize, i, j);
    return 0;
}

int put_all_back(myrpg_t *myrpg, int id)
{
    sfSprite_setTexture(myrpg->game_info->map,
        sfTexture_createFromFile(MAP_PATH, NULL), sfFalse);
    sfSprite_setScale(myrpg->game_info->map, (sfVector2f){1, 1});
    sfView_setCenter(myrpg->game_info->map_view, myrpg->fight_infos->pos);
    tp_all(myrpg, id, 1);
    sfSprite_setPosition(myrpg->game_info->player, myrpg->fight_infos->pos);
    sfSprite_setTextureRect(myrpg->mobs[id]->sprite, myrpg->mobs[id]->rect);
    sfSprite_setTextureRect(myrpg->game_info->player, myrpg->game_info->rect);
    return 0;
}
