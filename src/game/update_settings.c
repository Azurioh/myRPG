/*
** EPITECH PROJECT, 2024
** update_settings
** File description:
** Function to update scaling and position of settings in game
*/

#include "../../include/myrpg.h"

static void update_others_settings_button(button_t **buttons,
    sfVector2f resize, float scaling)
{
    int val1 = sfSprite_getPosition(buttons[8]->image_sprite).x;
    int val2 = sfSprite_getPosition(buttons[8]->image_sprite).y;

    for (int i = 8; i < 11; i++) {
        if (i == 9)
            continue;
        val1 = sfSprite_getPosition(buttons[i]->image_sprite).x;
        val2 = sfSprite_getPosition(buttons[i]->image_sprite).y;
        sfSprite_setPosition(buttons[i]->image_sprite,
            (sfVector2f)(sfVector2f){val1 + resize.x - (300 * scaling),
            val2 + resize.y - (300 * scaling)});
    }
}

static void update_settings_button(button_t **buttons, sfVector2f resize,
    float scaling)
{
    int val1 = sfSprite_getPosition(buttons[0]->image_sprite).x;
    int val2 = sfSprite_getPosition(buttons[0]->image_sprite).y;

    for (int i = 0; i <= 7; i++) {
        sfSprite_setPosition(buttons[i]->image_sprite,
            (sfVector2f){val1 + resize.x - (200 * scaling),
            val2 + resize.y - (100 * scaling)});
        if (i % 2 != 0) {
            val1 -= 100;
            val2 += 100;
        }
        if (i % 2 == 0) {
            val1 += 100;
        }
    }
    sfSprite_setPosition(buttons[9]->image_sprite,
        (sfVector2f){val1 + resize.x - (200 * scaling),
        val2 + resize.y - (100 * scaling)});
    update_others_settings_button(buttons, resize, scaling);
}

static void update_settings_texts(sfText **texts, sfVector2f resize)
{
    sfVector2f txt_pos;
    int j = 0;

    for (int i = 0; i < 4; i++) {
        txt_pos = sfText_getPosition(texts[i]);
        sfText_setPosition(texts[i],
            (sfVector2f){txt_pos.x + resize.x - 170,
            txt_pos.y + resize.y - 50 - (j * 40)});
        txt_pos = sfText_getPosition(texts[i + 5]);
        sfText_setPosition(texts[i + 5],
            (sfVector2f){txt_pos.x + resize.x - 240,
            txt_pos.y + resize.y - 50 - (j * 40)});
        j++;
    }
    txt_pos = sfText_getPosition(texts[4]);
    sfText_setPosition(texts[4],
        (sfVector2f){txt_pos.x + resize.x - 170,
        txt_pos.y + resize.y - 50 - (j * 40)});
}

static void update_settings_background(sfSprite *background, sfVector2f resize)
{
    sfVector2f bg_pos = sfSprite_getPosition(background);

    sfSprite_setPosition(background,
        (sfVector2f){bg_pos.x + resize.x - 330, bg_pos.y + resize.y - 200});
}

void update_settings_position(settings_t *settings,
    sfVector2f resize)
{
    update_settings_background(settings->visual_elements->background, resize);
    update_settings_button(settings->visual_elements->buttons, resize,
        settings->scaling);
    update_settings_texts(settings->visual_elements->texts, resize);
}

void update_settings_scaling(settings_t *settings)
{
    sfSprite_setScale(settings->visual_elements->background,
        (sfVector2f){ settings->scaling / 1.8, settings->scaling / 1.8});
    for (int i = 0; settings->visual_elements->buttons[i]; i++) {
        sfSprite_setScale(settings->visual_elements->buttons[i]->image_sprite,
            (sfVector2f){settings->scaling / 4, settings->scaling / 4});
        settings->visual_elements->buttons[i]->initial_scaling =
            settings->scaling / 4;
    }
    for (int i = 0; settings->visual_elements->texts[i]; i++) {
        sfText_setCharacterSize(settings->visual_elements->texts[i], 40);
        if (i > 4)
            sfText_setCharacterSize(settings->visual_elements->texts[i], 20);
    }
}
