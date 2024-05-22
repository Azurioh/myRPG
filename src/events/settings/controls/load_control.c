/*
** EPITECH PROJECT, 2024
** load_control
** File description:
** Function to load the editing controls elements
*/

#include "../../../../include/myrpg.h"

static void load_control_texts(myrpg_t *myrpg, int text_size)
{
    sfText **texts = malloc(sizeof(sfText *) * 5);
    sfColor color = sfColor_fromRGBA(200, 200, 200, 255);
    float scaling = SETTINGS->scaling;

    texts[0] = init_text("Modification des touches",
        (sfVector2f){ (960 * scaling), (200 * scaling)},
        text_size * scaling, sfWhite);
    texts[1] = init_text(
        "Appuyez sur la touche\n\ta utiliser pour :",
        (sfVector2f){ (960 * scaling), (350 * scaling)},
        text_size * scaling, sfWhite);
    texts[2] = init_text("Avancer",
        (sfVector2f){ (960 * scaling), (500 * scaling)},
        text_size * scaling, color);
    texts[3] = init_text("",
        (sfVector2f){ (810 * scaling), (600 * scaling)},
        text_size * scaling, sfRed);
    texts[4] = NULL;
    SETTINGS->visual_elements->texts = texts;
    SETTINGS->visual_elements->buttons = malloc(sizeof(button_t *));
    SETTINGS->visual_elements->buttons[0] = NULL;
}

static void load_control_texts_resized(myrpg_t *myrpg, sfVector2f resize,
    int text_size)
{
    sfText **texts = malloc(sizeof(sfText *) * 5);
    sfColor color = sfColor_fromRGBA(200, 200, 200, 255);

    texts[0] = init_text("Modification des touches",
        (sfVector2f){ resize.x + 960, resize.y + 200}, text_size, sfWhite);
    texts[1] = init_text(
        "Appuyez sur la touche\n\ta utiliser pour :",
        (sfVector2f){ resize.x + 960, resize.y + 300}, text_size, sfWhite);
    texts[2] = init_text("Avancer",
        (sfVector2f){ resize.x + 960, resize.y + 400}, text_size, color);
    texts[3] = init_text("",
        (sfVector2f){ resize.x + 880, resize.y + 500}, text_size, sfRed);
    texts[4] = NULL;
    SETTINGS->visual_elements->texts = texts;
    SETTINGS->visual_elements->buttons = malloc(sizeof(button_t *));
    SETTINGS->visual_elements->buttons[0] = NULL;
}

void load_control_elements(myrpg_t *myrpg)
{
    sfVector2f resize = get_resize(myrpg);
    int text_size = 55;

    if (resize.x != 0) {
        text_size = 35;
        resize.x -= 340;
        resize.y -= 50;
        load_control_texts_resized(myrpg, resize, text_size);
    } else {
        load_control_texts(myrpg, text_size);
    }
}
