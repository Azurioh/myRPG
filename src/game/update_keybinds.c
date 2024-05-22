/*
** EPITECH PROJECT, 2024
** update_keybinds
** File description:
** Function to update scaling and position of keybinds mapping
*/

#include "../../include/myrpg.h"

static void update_keybinds_position(sfSprite *background, sfText **texts,
    sfVector2f resize)
{
    sfSprite_setPosition(background,
        (sfVector2f){resize.x + 620, resize.y + 350});
    printf("DEBUG: %f | %f\n", resize.x, resize.y);
    sfText_setPosition(texts[0], (sfVector2f){resize.x + 420, resize.y + 140});
    sfText_setPosition(texts[1], (sfVector2f){resize.x + 420, resize.y + 200});
    sfText_setPosition(texts[2], (sfVector2f){resize.x + 420, resize.y + 260});
    sfText_setPosition(texts[3], (sfVector2f){resize.x + 420, resize.y + 320});
    sfText_setPosition(texts[4], (sfVector2f){resize.x + 420, resize.y + 380});
    sfText_setPosition(texts[5], (sfVector2f){resize.x + 530, resize.y + 145});
    sfText_setPosition(texts[6], (sfVector2f){resize.x + 560, resize.y + 205});
    sfText_setPosition(texts[7], (sfVector2f){resize.x + 530, resize.y + 265});
    sfText_setPosition(texts[8], (sfVector2f){resize.x + 620, resize.y + 325});
    sfText_setPosition(texts[9], (sfVector2f){resize.x + 620, resize.y + 325});
    sfText_setPosition(texts[10], (sfVector2f){resize.x + 620, resize.y + 325});
    sfText_setPosition(texts[11], (sfVector2f){resize.x + 620, resize.y + 325});
}

void update_keybinds_scaling(settings_t *settings, sfVector2f resize)
{
    sfSprite_setScale(settings->visual_elements->background,
        (sfVector2f){ settings->scaling / (1.7 * settings->scaling),
        settings->scaling / (1.7 * settings->scaling)});
    for (int i = 0; settings->visual_elements->texts[i]; i++) {
        sfText_setCharacterSize(settings->visual_elements->texts[i],
            55 * settings->scaling);
    }
    update_keybinds_position(settings->visual_elements->background,
        settings->visual_elements->texts, resize);
}
