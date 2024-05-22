/*
** EPITECH PROJECT, 2024
** update_settings
** File description:
** Function to update scaling and position of settings in game
*/

#include "../../include/myrpg.h"

static void update_others_settings_button(button_t **buttons,
    sfVector2f resize)
{
    sfSprite_setPosition(buttons[8]->image_sprite,
        (sfVector2f)(sfVector2f){resize.x + 625, resize.y + 470});
    sfSprite_setPosition(buttons[10]->image_sprite,
        (sfVector2f)(sfVector2f){resize.x + 625, resize.y + 550});
}

static void update_settings_button(button_t **buttons, sfVector2f resize)
{
    int x = 750;
    int y = 170;

    for (int i = 0; i <= 7; i++) {
        sfSprite_setPosition(buttons[i]->image_sprite,
            (sfVector2f){resize.x + x, resize.y + y});
        if (i % 2 != 0) {
            x -= 50;
            y += 60;
        }
        if (i % 2 == 0) {
            x += 50;
        }
    }
    sfSprite_setPosition(buttons[9]->image_sprite,
        (sfVector2f){resize.x + x, resize.y + y});
    update_others_settings_button(buttons, resize);
}

static void update_settings_texts(sfText **texts, sfVector2f resize)
{
    sfText_setPosition(texts[0], (sfVector2f){resize.x + 420, resize.y + 140});
    sfText_setPosition(texts[1], (sfVector2f){resize.x + 420, resize.y + 200});
    sfText_setPosition(texts[2], (sfVector2f){resize.x + 420, resize.y + 260});
    sfText_setPosition(texts[3], (sfVector2f){resize.x + 420, resize.y + 320});
    sfText_setPosition(texts[4], (sfVector2f){resize.x + 420, resize.y + 380});
    sfText_setPosition(texts[5], (sfVector2f){resize.x + 530, resize.y + 145});
    sfText_setPosition(texts[6], (sfVector2f){resize.x + 560, resize.y + 205});
    sfText_setPosition(texts[7], (sfVector2f){resize.x + 530, resize.y + 265});
    sfText_setPosition(texts[8], (sfVector2f){resize.x + 620, resize.y + 325});
}

static void update_settings_background(sfSprite *background, sfVector2f resize)
{
    sfSprite_setPosition(background,
        (sfVector2f){resize.x + 620, resize.y + 350});
}

void update_settings_position(settings_t *settings,
    sfVector2f resize)
{
    update_settings_background(settings->visual_elements->background, resize);
    update_settings_button(settings->visual_elements->buttons, resize);
    update_settings_texts(settings->visual_elements->texts, resize);
}

static void update_settings_buttons_scaling(settings_t *settings)
{
    sfSprite_setScale(settings->visual_elements->background,
        (sfVector2f){ settings->scaling / (1.7 * settings->scaling),
        settings->scaling / (1.7 * settings->scaling)});
    for (int i = 0; settings->visual_elements->buttons[i]; i++) {
        sfSprite_setScale(settings->visual_elements->buttons[i]->image_sprite,
            (sfVector2f){settings->scaling / (3 * settings->scaling),
            settings->scaling / (3 * settings->scaling)});
        settings->visual_elements->buttons[i]->initial_scaling =
            settings->scaling / (3 * settings->scaling);
    }
    sfSprite_setScale(settings->visual_elements->buttons[8]->image_sprite,
        (sfVector2f){settings->scaling / (1.8 * settings->scaling),
        settings->scaling / (1.8 * settings->scaling)});
    settings->visual_elements->buttons[8]->initial_scaling =
        settings->scaling / (1.8 * settings->scaling);
}

void update_settings_scaling(settings_t *settings)
{
    update_settings_buttons_scaling(settings);
    for (int i = 0; settings->visual_elements->texts[i]; i++) {
        sfText_setCharacterSize(settings->visual_elements->texts[i],
            40 / settings->scaling);
        if (i > 4)
            sfText_setCharacterSize(settings->visual_elements->texts[i],
                30 / settings->scaling);
    }
}
