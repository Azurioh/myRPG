/*
** EPITECH PROJECT, 2024
** load_control
** File description:
** Function to load the editing controls elements
*/

#include "../../../../include/myrpg.h"

static void load_control_texts(myrpg_t *myrpg)
{
    sfText **texts = malloc(sizeof(sfText *) * 5);
    sfColor color = sfColor_fromRGBA(200, 200, 200, 255);

    texts[0] = init_text("Modification des touches",
        (sfVector2f){ 960 * SETTINGS->scaling, 200 * SETTINGS->scaling},
        60 * SETTINGS->scaling, sfWhite);
    texts[1] = init_text(
        "Appuyez sur la touche\n\ta utiliser pour :",
        (sfVector2f){ 960 * SETTINGS->scaling, 350 * SETTINGS->scaling},
        50 * SETTINGS->scaling, sfWhite);
    texts[2] = init_text("Avancer",
        (sfVector2f){ 960 * SETTINGS->scaling, 500 * SETTINGS->scaling},
        55 * SETTINGS->scaling, color);
    texts[3] = init_text("",
        (sfVector2f){ 820 * SETTINGS->scaling, 600 * SETTINGS->scaling},
        50 * SETTINGS->scaling, sfRed);
    texts[4] = NULL;
    SETTINGS->visual_elements->texts = texts;
    SETTINGS->visual_elements->buttons = malloc(sizeof(button_t *));
    SETTINGS->visual_elements->buttons[0] = NULL;
}

void load_control_elements(myrpg_t *myrpg)
{
    load_control_texts(myrpg);
}
