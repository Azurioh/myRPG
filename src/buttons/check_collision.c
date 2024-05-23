/*
** EPITECH PROJECT, 2024
** check_collision.c
** File description:
** Function to check the collision with the mouse and a button
*/

#include "../../include/myrpg.h"
#include <stdio.h>

static sfVector2f get_attack_button_pos(button_attack_t *button)
{
    sfVector2f position = sfSprite_getPosition(button->image_sprite);
    sfFloatRect button_size = sfSprite_getGlobalBounds(button->image_sprite);

    position.x -= button_size.width / 2;
    position.y -= button_size.height / 2;
    return position;
}

int check_attack_collision(button_attack_t *button, sfRenderWindow *window)
{
    sfVector2f button_pos = get_attack_button_pos(button);
    sfFloatRect button_size = sfSprite_getGlobalBounds(button->image_sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfView const *view = sfRenderWindow_getView(window);
    sfVector2f mousepos = sfRenderWindow_mapPixelToCoords(window, mouse, view);

    if (mousepos.x > button_pos.x
        && mousepos.x < button_pos.x + button_size.width)
        if (mousepos.y > button_pos.y
            && mousepos.y < button_pos.y + button_size.height) {
            return 1;
        }
    return 0;
}

static sfVector2f get_button_pos(button_t *button)
{
    sfVector2f position = sfSprite_getPosition(button->image_sprite);
    sfFloatRect button_size = sfSprite_getGlobalBounds(button->image_sprite);

    position.x -= button_size.width / 2;
    position.y -= button_size.height / 2;
    return position;
}

int check_collision(button_t *button, sfRenderWindow *window)
{
    sfVector2f button_pos = get_button_pos(button);
    sfFloatRect button_size = sfSprite_getGlobalBounds(button->image_sprite);
    sfVector2f m_pos = get_mouse_position(window);

    if (m_pos.x > button_pos.x
        && m_pos.x < button_pos.x + button_size.width)
        if (m_pos.y > button_pos.y
            && m_pos.y < button_pos.y + button_size.height) {
            return 1;
        }
    return 0;
}
