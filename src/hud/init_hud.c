/*
** EPITECH PROJECT, 2024
** init_hud
** File description:
** load all the sprite for the hud
*/

#include "../../include/myrpg.h"

image_t *create_image_from_file(char *path, int x, int y, int scale)
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

hud_t *init_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->profile = create_image_from_file("assets/hud/profile.png", 4, 4, 2);
    hud->level = create_image_from_file("assets/hud/level.png", 148, 56, 2);
    hud->life = create_image_from_file("assets/hud/life.png", 148, 16, 2);
    return hud;
}
