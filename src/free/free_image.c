/*
** EPITECH PROJECT, 2024
** free_myrpg
** File description:
** Free the myrpg struct
*/

#include "../../include/myrpg.h"

void free_image(image_t *image)
{
    if (image == NULL) {
        return;
    }
    sfTexture_destroy(image->texture);
    sfSprite_destroy(image->sprite);
}
