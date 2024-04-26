/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"

hud_t *init_hud(char *name)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->profile = create_imagefile("assets/hud/profile.png", 4, 4, 2);
    hud->exp = create_imagefile("assets/hud/level.png", 148, 96, 2);
    hud->life = create_imagefile("assets/hud/life.png", 148, 56, 2);
    hud->inventory = create_imagefile("assets/hud/bag.png", 1800, 400, 2);
    hud->font = sfFont_createFromFile("assets/font/alagard.ttf");
    hud->action = create_text("F", 48, (sfVector2f){1050, 450}, hud->font);
    hud->name = create_text(name, 32, (sfVector2f){130, 6}, hud->font);
    hud->act_text = create_text("E", 48, (sfVector2f){1840, 500}, hud->font);
    hud->skill = create_imagefile("assets/hud/notification.png", 1050, 15, 1);
    hud->skill_text = create_text("Nombre d'ameliorations disponibles :",
    26, (sfVector2f){1130, 43}, hud->font);
    return hud;
}
