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
    #include "settings.h"

typedef struct keybinds_s {
    int move_up;
    int move_down;
    int move_left;
    int move_right;
    int open_inventory;
    int interact;
} keybinds_t;

typedef struct game_menu_s {
    sfSprite *background;
    button_t **buttons;
} game_menu_t;

typedef struct game_s {
    sfSprite *player;
    sfSprite *map;
    sfImage *undermap;
    sfView *map_view;
    game_menu_t *game_menu;
    sfBool show_menu;
    keybinds_t *keybinds;
} game_t;

game_t *init_game_struct(settings_t *settings);
void free_game(game_t *game_info);
game_menu_t *init_game_menu(game_t *game_info, settings_t *settings);

void update_settings_position(settings_t *settings,
    sfVector2f resize);
void update_settings_scaling(settings_t *settings);
#endif
