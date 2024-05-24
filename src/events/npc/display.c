/*
** EPITECH PROJECT, 2024
** display.c
** File description:
** Function to display npc talk
*/

#include "../../../include/myrpg.h"
#include "SFML/Graphics/RectangleShape.h"
#include "SFML/Graphics/Text.h"
#include "SFML/Graphics/Types.h"

void display_npc_talk(void *args)
{
    myrpg_t *myrpg = args;
    sfVector2f resize = get_resize(myrpg);

    resize.y += 500;
    EVENTS->previous_display_function(myrpg);
    sfRectangleShape_setPosition(NPC->visual->rect, resize);
    resize.x += 20;
    sfText_setPosition(NPC->visual->text, resize);
    sfRenderWindow_drawRectangleShape(WINDOW, NPC->visual->rect, NULL);
    sfRenderWindow_drawText(WINDOW, NPC->visual->text, NULL);
}
