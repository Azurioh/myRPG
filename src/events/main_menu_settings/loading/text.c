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
    sfColor color = sfColor_fromRGBA(200, 200, 200, 255);

    texts[0] = init_text("FPS :", (sfVector2f){ 620 * settings->scaling,
        200 * settings->scaling}, 60, color);
    texts[1] = init_text("Taille :", (sfVector2f){ 620 *
        settings->scaling, 320 * settings->scaling}, 60, color);
    texts[2] = init_text("Son :", (sfVector2f){ 620 * settings->scaling,
        440 * settings->scaling}, 60, color);
    texts[3] = init_text("Musique :", (sfVector2f){ 620 * settings->scaling,
        560 * settings->scaling}, 60, color);
    for (int i = 0; i < 4; i++) {
        sfText_setScale(texts[i], (sfVector2f){scaling, scaling});
        sfText_setOrigin(texts[i], (sfVector2f){0, 0});
    }
}

void load_dynamic_settings_texts(sfText **texts, settings_t *settings)
{
    float scaling = settings->scaling;

    texts[4] = init_text("60", (sfVector2f){ 800 * settings->scaling,
        210 * settings->scaling}, 40, sfWhite);
    texts[5] = init_text("1920x1080", (sfVector2f){ 850 * settings->scaling,
        330 * settings->scaling}, 40, sfWhite);
    texts[6] = init_text("50%", (sfVector2f){ 800 * settings->scaling,
        450 * settings->scaling}, 40, sfWhite);
    texts[7] = init_text("50%", (sfVector2f){ 920 * settings->scaling,
        573 * settings->scaling}, 40, sfWhite);
    for (int i = 4; i < 8; i++) {
        sfText_setScale(texts[i], (sfVector2f){scaling * 1.2, scaling * 1.2});
        sfText_setOrigin(texts[i], (sfVector2f){0, 0});
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
