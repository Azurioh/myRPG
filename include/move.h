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
    #include "inventory.h"
    #define MOVE_UP sfKeyUp
    #define MOVE_DOWN sfKeyDown
    #define MOVE_LEFT sfKeyLeft
    #define MOVE_RIGHT sfKeyRight

void move_hud(hud_t *hud, int x, int y);
void move_inventory(inventory_t *inventory, int x_move, int y_move);
#endif
