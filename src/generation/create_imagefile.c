/*
** EPITECH PROJECT, 2024
** create_imagefile
** File description:
** load an image and create a sprite with his texture
*/

#include "../../include/myrpg.h"

image_t *create_imagefile(char *path, int x, int y, float scale)
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
