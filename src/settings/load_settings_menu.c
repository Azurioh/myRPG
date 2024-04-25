/*
** EPITECH PROJECT, 2024
** load_settings_menu.c
** File description:
** Function to load the visual of the settings menu
*/

#include "../../include/myrpg.h"

static sfSprite *load_settings_background(sfRenderWindow *window,
    float scaling)
{
    sfSprite *sprite = generate_sprite_with_file(
        "assets/settings_background.png", scaling);
    sfFloatRect size;
    sfVector2u window_size;

    size = sfSprite_getGlobalBounds(sprite);
    window_size = sfRenderWindow_getSize(window);
    sfSprite_setOrigin(sprite,
        (sfVector2f){ size.width / 2, size.height / 2 });
    sfSprite_setPosition(sprite,
        (sfVector2f){ (float)window_size.x / 2.0,
        (float)window_size.y / 2.0 });
    return sprite;
}

void load_settings_menu(settings_t *settings)
{
    settings_visual_t *visual_elements = malloc(sizeof(settings_visual_t));

    if (!visual_elements) {
        settings->visual_elements = NULL;
        return;
    }
    visual_elements->background = load_settings_background(settings->window,
        settings->scaling);
    visual_elements->buttons = load_settings_buttons(settings);
    visual_elements->texts = load_settings_texts(settings);
    settings->visual_elements = visual_elements;
}
