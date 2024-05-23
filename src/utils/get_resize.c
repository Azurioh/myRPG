/*
** EPITECH PROJECT, 2024
** get_resize
** File description:
** Get the resize value
*/

#include "../../include/myrpg.h"

sfVector2f get_resize(myrpg_t *myrpg)
{
    sfVector2f center;
    sfVector2f size;
    sfVector2f resize;

    if (!GAME_INFO || !GAME_INFO->map_view) {
        return (sfVector2f){0, 0};
    }
    center = sfView_getCenter(GAME_INFO->map_view);
    size = sfView_getSize(GAME_INFO->map_view);
    resize = (sfVector2f){center.x - size.x / 2, center.y - size.y / 2};
    return resize;
}
