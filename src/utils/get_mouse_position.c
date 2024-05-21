/*
** EPITECH PROJECT, 2024
** get_mouse_position
** File description:
** get mouse position
*/
#include "../../include/myrpg.h"

sfVector2f get_mouse_position(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfView const *view = sfRenderWindow_getView(window);

    return sfRenderWindow_mapPixelToCoords(window, mouse, view);
}
