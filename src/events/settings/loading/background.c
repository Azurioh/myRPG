/*
** EPITECH PROJECT, 2024
** background.c
** File description:
** Function to load the visual of the settings menu
*/

#include "../../../../include/myrpg.h"

sfSprite *load_settings_background(sfRenderWindow *window,
    float scaling)
{
    sfSprite *sprite = generate_sprite_with_file(
        "assets/settings-background.png", 1);
    sfFloatRect size;
    sfVector2u window_size;

    size = sfSprite_getGlobalBounds(sprite);
    window_size = sfRenderWindow_getSize(window);
    sfSprite_setOrigin(sprite,
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfSprite_setPosition(sprite,
        (sfVector2f){ ((float)window_size.x / 2.),
        ((float)window_size.y / 2.0) });
    sfSprite_setScale(sprite, (sfVector2f){scaling, scaling});
    return sprite;
}
