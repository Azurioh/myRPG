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

typedef struct game_s {
    sfRenderWindow *window;
    sfVideoMode *window_size_list;
    sfVector2f scaling;
    sfEvent event;
    sfSprite *player;
    sfSprite *map;
    sfSprite *undermap;
    sfView *map_view;
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

int change_size_of_window(game_t *game_info, int add);
int init_window(game_t *game_info);

int mute_music(game_t *game_info);
int mute_sound(game_t *game_info);

int increase_music_volume(game_t *game_info);
int increase_sound_volume(game_t *game_info);
int increase_framerate_of_window(game_t *game_info);
int increase_size_of_window(game_t *game_info);

int decrease_music_volume(game_t *game_info);
int decrease_sound_volume(game_t *game_info);
int decrease_framerate_of_window(game_t *game_info);
int decrease_size_of_window(game_t *game_info);
#endif
