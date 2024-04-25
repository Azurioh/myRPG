/*
** EPITECH PROJECT, 2024
** load_settings_text.c
** File description:
** Function to load the text of the setting menu
*/

#include "../../include/myrpg.h"

void load_static_settings_texts(sfText **texts, settings_t *settings)
{
    texts[0] = init_text("FPS", (sfVector2f){ 800 * settings->scaling,
        380 * settings->scaling}, 40, sfBlack);
    texts[1] = init_text("Resolution", (sfVector2f){ 1120 * settings->scaling,
        380 * settings->scaling}, 40, sfBlack);
    texts[2] = init_text("Musique", (sfVector2f){ 800 * settings->scaling,
        630 * settings->scaling}, 40, sfBlack);
    texts[3] = init_text("Son", (sfVector2f){ 1120 * settings->scaling,
        630 * settings->scaling}, 40, sfBlack);
}

void load_dynamic_settings_texts(sfText **texts, settings_t *settings)
{
    texts[4] = init_text("60", (sfVector2f){ 800 * settings->scaling,
        440 * settings->scaling}, 30, sfBlack);
    texts[5] = init_text("1920x1080", (sfVector2f){ 1120 * settings->scaling,
        440 * settings->scaling}, 30, sfBlack);
    texts[6] = init_text("50%", (sfVector2f){ 800 * settings->scaling,
        690 * settings->scaling}, 30, sfBlack);
    texts[7] = init_text("50%", (sfVector2f){ 1120 * settings->scaling,
        690 * settings->scaling}, 30, sfBlack);
}

sfText **load_settings_texts(settings_t *settings)
{
    sfText **texts = malloc(sizeof(sfText *) * 9);

    load_static_settings_texts(texts, settings);
    load_dynamic_settings_texts(texts, settings);
    texts[8] = NULL;
    return texts;
}
