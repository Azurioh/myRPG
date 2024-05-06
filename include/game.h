/*
** EPITECH PROJECT, 2024
** game.h
** File description:
** All protos and struct about the game infos
*/

#ifndef GAME_H
    #define GAME_H
    #include <SFML/Graphics.h>
    #include "button.h"

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode *window_size_list;
    sfVector2f scaling;
    sfEvent event;
    int actual_window_size;
    unsigned int *framerate_list;
    int actual_framerate;
    int sound_volume;
    int sound_muted;
    int music_volume;
    int music_muted;
} game_t;

game_t *init_game_struct(void);
void free_game(game_t *game_info);
#endif
