/*
** EPITECH PROJECT, 2024
** myrpg.h
** File description:
** All protos, include and struct for the project
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include "player.h"
    #include "game.h"

typedef struct myrpg_s {
    game_t *game_info;
    player_t *player;
} myrpg_t;

#endif
