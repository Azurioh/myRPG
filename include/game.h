/*
** EPITECH PROJECT, 2024
** game.h
** File description:
** All protos and struct about the game infos
*/

#ifndef GAME_H
    #define GAME_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include "button.h"

typedef struct keybinds_s {
    int move_up;
    int move_down;
    int move_left;
    int move_right;
    int open_inventory;
    int interact;
} keybinds_t;
typedef struct game_s {
    sfSprite *player;
    sfSprite *map;
    sfImage *undermap;
    sfView *map_view;
    keybinds_t *keybinds;
} game_t;

game_t *init_game_struct(void);
void free_game(game_t *game_info);
#endif
