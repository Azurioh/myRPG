/*
** EPITECH PROJECT, 2024
** button.h
** File description:
** All protos and struct about the buttons
*/

#ifndef BUTTON_H
    #define BUTTON_H
    #include <SFML/Graphics.h>

typedef struct button_s {
    char *button_name;
    sfVector2f position;
    sfSprite *image_sprite;
    sfBool actually_hover;
    sfBool actually_clicked;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *,
        sfRenderWindow *);
    sfBool (*is_hover)(struct button_s *, sfMouseButtonEvent *,
        sfRenderWindow *);
    void (*action)(void *args);
} button_t;

void free_button(button_t *button);
void free_all_buttons(button_t **buttons);
button_t *init_button(char *button_name, sfVector2f position,
    char *image_path, void (*action)(void *));
#endif
