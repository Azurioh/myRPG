/*
** EPITECH PROJECT, 2024
** create_text
** File description:
** create a text from a string, a size, a position and a font
*/

#include "../../include/myrpg.h"

sfText *create_text(char *string, int size, sfVector2f position, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setOutlineThickness(text, 2);
    return text;
}
