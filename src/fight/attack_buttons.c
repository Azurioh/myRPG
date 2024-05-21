/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** buttons for the attack
*/

#include "../../include/myrpg.h"
#include "../../include/fight.h"
#include "../../include/button.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static sfBool is_btn_clicked(button_attack_t *button, sfRenderWindow *window)
{
    if (check_attack_collision(button, window)) {
        putc('\n', stdout);
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

static sfBool is_hover(button_attack_t *button, sfRenderWindow *window)
{
    if (check_attack_collision(button, window)) {
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

button_attack_t *init_attack_button(char *button_name, sfVector2f position,
    char *image_path, char *(*action)(void *))
{
    button_attack_t *button = malloc(sizeof(button_t));

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
    button->action = action;
    return button;
}

button_attack_t **setup_attack_buttons(myrpg_t *myrpg)
{
    button_attack_t **buttons = malloc(sizeof(button_t *) * 5);
    sfVector2f pos = sfView_getCenter(myrpg->game_info->map_view);

    buttons[0] = init_attack_button("Lancer de hache",
        (sfVector2f){(pos.x + 1050) * 0.65, (pos.y + 700) * 0.65},
        "assets/attaque_hache.png", &axe_throw);
    buttons[1] = init_attack_button("Lancer de hache",
        (sfVector2f){(pos.x + 1050) * 0.65, (pos.y + 600) * 0.65},
        "assets/attaque_hache.png", &drink_hydromel);
    buttons[2] = init_attack_button("Lancer de hache",
        (sfVector2f){(pos.x + 1050) * 0.65, (pos.y + 500) * 0.65},
        "assets/attaque_hache.png", &another_attack);
    buttons[3] = init_attack_button("Lancer de hache",
        (sfVector2f){(pos.x + 1050) * 0.65, (pos.y + 400) * 0.65},
        "assets/attaque_hache.png", &angry_guy);
    for (int i = 0; i < 4; i++) {
        sfSprite_scale(buttons[i]->image_sprite, (sfVector2f){0.5, 0.5});
        buttons[i]->initial_scaling = 0.5;
    }
    return buttons;
}
