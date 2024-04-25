/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"

image_t *create_imagefile(char *path, int x, int y, int scale)
{
    image_t *image = malloc(sizeof(image_t));

    image->texture = sfTexture_createFromFile(path, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    if (scale != 0)
        sfSprite_setScale(image->sprite, (sfVector2f){scale, scale});
    sfSprite_setPosition(image->sprite, (sfVector2f){x, y});
    return image;
}

sfText *create_text(char *string, int size, sfVector2f position, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setOutlineThickness(text, 2);
    return text;
}

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
    return hud;
}
