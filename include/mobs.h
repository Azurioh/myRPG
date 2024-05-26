/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** mobs.h
*/


#pragma once
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Time.h>

typedef struct mobs_s {
    sfRectangleShape *hitbox;
    sfCircleShape *detection;
    sfVector2f pos;
    sfClock *clock;
    sfClock *clock_move;
    sfSprite *sprite;
    sfIntRect rect;
    sfTime respawn;
    int id;
    int can_collide;
    int xp_loot;
    int **item_loot;
    int level;
    int damages;
    int life;
} mobs_t;

int **init_loot(void);
mobs_t *create_sprite(mobs_t *mobs);
mobs_t *create_boss_sprite(mobs_t *mobs);
mobs_t *init_lvl_one(mobs_t **mobs, int i, sfVector2f pos);
void free_mobs(mobs_t **mobs);
mobs_t *init_lvl_two(mobs_t **mobs, int i, sfVector2f pos);
mobs_t *init_lvl_three(mobs_t **mobs, int i, sfVector2f pos);
mobs_t *init_lvl_four(mobs_t **mobs, int i, sfVector2f pos);
mobs_t *init_lvl_boss(mobs_t **mobs, int i, sfVector2f pos);
