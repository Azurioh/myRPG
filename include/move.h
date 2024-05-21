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

void move_hud(hud_t *hud, sfVector2f movement);
void move_inventory(inventory_t *inventory, sfVector2f movement);
#endif
