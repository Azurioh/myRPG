/*
** EPITECH PROJECT, 2024
** background.c
** File description:
** Function to load the background of npc talk
*/

#include "../../../../include/myrpg.h"

sfRectangleShape *load_npc_background(myrpg_t *myrpg)
{
    sfRectangleShape *background = sfRectangleShape_create();
    sfVector2f resize = get_resize(myrpg);

    sfRectangleShape_setSize(background, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(background, sfWhite);
    sfRectangleShape_setOutlineColor(background, sfBlack);
    sfRectangleShape_setPosition(background,
        (sfVector2f){resize.x, resize.y + 540});
    return background;
}
