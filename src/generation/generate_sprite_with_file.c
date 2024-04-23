/*
** EPITECH PROJECT, 2024
** generate_sprite_with_file
** File description:
** Function to generate a sprite with a texture created with a file
*/

#include "../../include/myrpg.h"

sfSprite *generate_sprite_with_file(char *file_path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}
