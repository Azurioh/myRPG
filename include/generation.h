/*
** EPITECH PROJECT, 2024
** generation.h
** File description:
** All functions to generate some elements
*/

#ifndef GENERATION_H
    #define GENERATION_H
    #include <SFML/Graphics.h>
    #define FIGHT_MAP "assets/combat_scene.png"
    #define UNDERMAP_PATH "./assets/map/undermap.png"
    #define MAP_PATH "./assets/map/map.png"
    #define PLAYER_PATH "./assets/player_spritesheet.png"
    #define NPC "./assets/test_npc.png"

typedef struct image_s {
    sfTexture *texture;
    sfSprite *sprite;
} image_t;

image_t *create_imagefile(char *path, int x, int y, float scale);
sfText *create_text(char *string, int size, sfVector2f position, sfFont *font);
char *my_strdup(char const *str);

sfSprite *generate_sprite_with_file(char *file_path, float scaling);
#endif
