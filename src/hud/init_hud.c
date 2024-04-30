/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>

void init_text(hud_t *hud, sfVector2f resize, char *name)
{
    hud->font = sfFont_createFromFile("assets/font/alagard.ttf");
    hud->action = create_text("F", 48, (sfVector2f){resize.x + 1050,
                                resize.y + 450}, hud->font);
    hud->name = create_text(name, 32, (sfVector2f){resize.x + 130,
                                resize.y + 6}, hud->font);
    hud->act_text = create_text("E", 48, (sfVector2f){resize.x + 1840,
                                resize.y + 500}, hud->font);
    hud->skill_text = create_text("Nombre d'ameliorations disponibles :",
    26, (sfVector2f){resize.x + 1130, resize.y + 43}, hud->font);
}

hud_t *init_hud(char *name, game_t *game_info)
{
    hud_t *hud = malloc(sizeof(hud_t));
    sfVector2f center = sfView_getCenter(game_info->map_view);
    sfVector2f size = sfView_getSize(game_info->map_view);
    sfVector2f resize = {center.x - size.x / 2, center.y - size.y / 2};

    hud->profile = create_imagefile("assets/hud/profile.png", resize.x + 4,
                                resize.y + 4, 2);
    hud->exp = create_imagefile("assets/hud/level.png", resize.x + 148,
                                resize.y + 96, 2);
    hud->life = create_imagefile("assets/hud/life.png", resize.x + 148,
                                resize.y + 56, 2);
    hud->inventory = create_imagefile("assets/hud/bag.png", resize.x + 1800,
                                resize.y + 400, 2);
    hud->skill = create_imagefile("assets/hud/notification.png",
                                resize.x + 1050, resize.y + 15, 1);
    init_text(hud, resize, name);
    return hud;
}
