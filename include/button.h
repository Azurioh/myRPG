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
    sfBool (*is_clicked)(struct button_s *, sfRenderWindow *);
    sfBool (*is_hover)(struct button_s *, sfRenderWindow *);
    sfClock *animation_clock;
    void (*action)(struct button_s *, void *args);
} button_t;

void free_button(button_t *button);
void free_all_buttons(button_t **buttons);
button_t *init_button(char *button_name, sfVector2f position,
    char *image_path, void (*action)(button_t *, void *));

int check_collision(button_t *button, sfRenderWindow *window);
#endif
