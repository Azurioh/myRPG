/*
** EPITECH PROJECT, 2024
** generate_sprite_with_file
** File description:
** Function to generate a sprite with a texture created with a file
*/

#include "../../include/myrpg.h"

sfSprite *generate_sprite_with_file(char *file_path, float scaling)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);

    if (!texture) {
        return NULL;
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setScale(sprite, (sfVector2f){scaling, scaling});
    return sprite;
}
