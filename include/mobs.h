/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** mobs.h
*/


#pragma once
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>

typedef struct mobs_s {
    sfRectangleShape *hitbox;
    sfVector2f pos;
    int id;
    int can_collide;
    int xp_loot;
    int item_loot;
    int level;
    int damages;
    int life;
} mobs_t;
