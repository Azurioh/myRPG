/*
** EPITECH PROJECT, 2024
** init_text
** File description:
** Function to init a sfText
*/

#include "../../include/myrpg.h"

sfText *init_text(char *txt, sfVector2f position, unsigned int size,
    sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/alagard.ttf");
    sfFloatRect size_text;

    sfText_setString(text, txt);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setPosition(text, position);
    size_text = sfText_getGlobalBounds(text);
    sfText_setOrigin(text,
        (sfVector2f){ size_text.width / 2, size_text.height / 2});
    return text;
}
