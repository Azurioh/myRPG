/*
** EPITECH PROJECT, 2024
** generation.h
** File description:
** All functions to generate some elements
*/

#ifndef GENERATION_H
    #define GENERATION_H
    #include <SFML/Graphics.h>
    #define UNDERMAP_PATH "assets/test.png"
    #define MAP_PATH "assets/test.png"
    #define PLAYER_PATH "assets/player_spritesheet.png"

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

image_t *create_imagefile(char *path, int x, int y, float scale);
sfText *create_text(char *string, int size, sfVector2f position, sfFont *font);
char *my_strdup(char const *str);

sfSprite *generate_sprite_with_file(char *file_path, float scaling);
#endif
