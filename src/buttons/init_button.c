/*
** EPITECH PROJECT, 2024
** init_button
** File description:
** Function to init a button_t struct
*/

#include "../../include/myrpg.h"

static sfBool is_btn_clicked(button_t *button, sfRenderWindow *window)
{
    if (check_collision(button, window)) {
        sfSprite_setColor(button->image_sprite,
            sfColor_fromRGBA(255, 255, 0, 255));
        button->actually_clicked = sfTrue;
        return sfTrue;
    }
    sfSprite_setColor(button->image_sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
    button->actually_clicked = sfFalse;
    button->is_hover(button, window);
    return sfFalse;
}

static void release_button(button_t *button)
{
    sfSprite_setColor(button->image_sprite,
        sfColor_fromRGBA(255, 255, 255, 255));
}

static sfBool is_hover(button_t *button, sfRenderWindow *window)
{
    if (check_collision(button, window)) {
        button->actually_hover = sfTrue;
        return sfTrue;
    }
    button->actually_hover = sfFalse;
    return sfFalse;
}

static sfSprite *init_button_sprite(char *image_path, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(image_path, NULL);
    sfFloatRect size;

    sfSprite_setTexture(sprite, texture, sfFalse);
    size = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){size.width / 2, size.height / 2});
    sfSprite_setPosition(sprite, position);
    return sprite;
}

button_t *init_button(char *button_name, sfVector2f position,
    char *image_path, void (*action)(button_t *, void *))
{
    button_t *button = malloc(sizeof(button_t));

    if (!button) {
        return NULL;
    }
    button->button_name = strdup(button_name);
    button->position = position;
    button->animation_clock = sfClock_create();
    button->image_sprite = init_button_sprite(image_path, button->position);
    button->actually_hover = sfFalse;
    button->actually_clicked = sfFalse;
    button->is_clicked = &is_btn_clicked;
    button->is_hover = &is_hover;
    button->release = &release_button;
    button->clickable = sfTrue;
    button->action = action;
    return button;
}
