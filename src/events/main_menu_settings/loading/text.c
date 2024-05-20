/*
** EPITECH PROJECT, 2024
** text.c
** File description:
** Function to load the text of the setting menu
*/

#include "../../../../include/myrpg.h"

void load_static_settings_texts(sfText **texts, settings_t *settings)
{
    float scaling = settings->scaling;

    texts[0] = init_text("FPS", (sfVector2f){ 692 * settings->scaling,
        280 * settings->scaling}, 40, sfBlack);
    texts[1] = init_text("Resolution", (sfVector2f){ 1210 * settings->scaling,
        280 * settings->scaling}, 40, sfBlack);
    texts[2] = init_text("Musique", (sfVector2f){ 692 * settings->scaling,
        630 * settings->scaling}, 40, sfBlack);
    texts[3] = init_text("Son", (sfVector2f){ 1120 * settings->scaling,
        630 * settings->scaling}, 40, sfBlack);
    for (int i = 0; i < 4; i++) {
        sfText_setScale(texts[i], (sfVector2f){scaling, scaling});
    }
}

void load_dynamic_settings_texts(sfText **texts, settings_t *settings)
{
    float scaling = settings->scaling;
    sfFloatRect rect;

    texts[4] = init_text("60", (sfVector2f){ 690 * settings->scaling,
        338 * settings->scaling}, 30, sfBlack);
    texts[5] = init_text("1920x1080", (sfVector2f){ 1208 * settings->scaling,
        340 * settings->scaling}, 30, sfBlack);
    texts[6] = init_text("50%", (sfVector2f){ 700 * settings->scaling,
        690 * settings->scaling}, 30, sfBlack);
    texts[7] = init_text("50%", (sfVector2f){ 1120 * settings->scaling,
        690 * settings->scaling}, 30, sfBlack);
    for (int i = 4; i < 8; i++) {
        sfText_setScale(texts[i], (sfVector2f){scaling * 1.2, scaling * 1.2});
        rect = sfText_getGlobalBounds(texts[i]);
        sfText_setOrigin(texts[i],
            (sfVector2f){(rect.width / 2) / 1.2, (rect.height / 2) / 1.2});
    }
}

sfText **load_settings_texts(settings_t *settings)
{
    sfText **texts = malloc(sizeof(sfText *) * 9);

    load_static_settings_texts(texts, settings);
    load_dynamic_settings_texts(texts, settings);
    texts[8] = NULL;
    return texts;
}
