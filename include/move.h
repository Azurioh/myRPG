/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** .h for the moving of the map
*/

#ifndef MOVE_H
    #define MOVE_H
    #include "game.h"
    #include "hud.h"
    #define MOVE_UP sfKeyUp
    #define MOVE_DOWN sfKeyDown
    #define MOVE_LEFT sfKeyLeft
    #define MOVE_RIGHT sfKeyRight

void move_down_view(game_t *game_info, hud_t *hud);
void move_up_view(game_t *game_info, hud_t *hud);
void move_left_view(game_t *game_info, hud_t *hud);
void move_right_view(game_t *game_info, hud_t *hud);
void move_hud(hud_t *hud, int x, int y);
#endif
