/*
** EPITECH PROJECT, 2024
** generation.h
** File description:
** All functions to generate some elements
*/

#ifndef GENERATION_H
    #define GENERATION_H
    #include <SFML/Graphics.h>

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;


sfSprite *generate_sprite_with_file(char *file_path);
image_t *create_imagefile(char *path, int x, int y, float scale);
sfText *create_text(char *string, int size, sfVector2f position, sfFont *font);
#endif
