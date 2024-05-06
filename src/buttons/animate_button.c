/*
** EPITECH PROJECT, 2024
** animate_button.c
** File description:
** Function to animate the button where the cursor is hover or not
*/

#include "../../include/myrpg.h"

static void animate_hover(button_t *button, sfVector2f scale)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(button->animation_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        scale.x += 0.05;
        scale.y += 0.05;
        sfSprite_setScale(button->image_sprite, scale);
        sfClock_restart(button->animation_clock);
    }
}

static void animate_not_hover(button_t *button, sfVector2f scale)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(button->animation_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        scale.x -= 0.05;
        scale.y -= 0.05;
        sfSprite_setScale(button->image_sprite, scale);
        sfClock_restart(button->animation_clock);
    }
}

void animate_button(button_t *button)
{
    sfVector2f scale = sfSprite_getScale(button->image_sprite);

    if (!button) {
        return;
    }
    if (scale.x < button->initial_scaling + 0.1 && button->actually_hover == sfTrue) {
        animate_hover(button, scale);
    }
    if (scale.x > button->initial_scaling && button->actually_hover == sfFalse) {
        animate_not_hover(button, scale);
    }
}
