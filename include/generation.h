/*
** EPITECH PROJECT, 2024
** generation.h
** File description:
** All functions to generate some elements
*/

#ifndef GENERATION_H
    #define GENERATION_H
    #include <SFML/Graphics.h>

    #define MAP_PATH "assets/test.png"
    #define PLAYER_PATH "assets/player_sprite.png"

sfSprite *generate_sprite_with_file(char *file_path);
#endif
