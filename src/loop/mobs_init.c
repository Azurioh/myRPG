/*
** EPITECH PROJECT, 2024
** MyRPG
** File description:
** Mobs initiation
*/

#include "../../include/mobs.h"
#include <stdio.h>
#include "../../include/myrpg.h"

mobs_t *init_lvl_one(mobs_t **mobs, int i, sfVector2f pos)
{
    mobs[i] = malloc(sizeof(mobs_t));
    mobs[i]->life = 100;
    mobs[i]->id = i;
    mobs[i]->can_collide = 1;
    mobs[i]->level = 1;
    mobs[i]->damages = 10;
    mobs[i]->xp_loot = 40;
    mobs[i]->item_loot = init_loot();
    mobs[i]->pos = pos;
    mobs[i]->clock = sfClock_create();
    mobs[i]->respawn = sfSeconds(30);
    mobs[i]->hitbox = sfRectangleShape_create();
    mobs[i]->detection = sfCircleShape_create();
    sfCircleShape_setRadius(mobs[i]->detection, 300);
    sfCircleShape_setPosition(mobs[i]->detection, pos);
    mobs[i] = create_sprite(mobs[i]);
    sfRectangleShape_setPosition(mobs[i]->hitbox, mobs[i]->pos);
    sfRectangleShape_setSize(mobs[i]->hitbox, (sfVector2f){50, 50});
    return mobs[i];
}

mobs_t *init_lvl_two(mobs_t **mobs, int i, sfVector2f pos)
{
    mobs[i] = malloc(sizeof(mobs_t));
    mobs[i]->life = 150;
    mobs[i]->id = i;
    mobs[i]->can_collide = 1;
    mobs[i]->level = 2;
    mobs[i]->damages = 20;
    mobs[i]->xp_loot = 50;
    mobs[i]->item_loot = init_loot();
    mobs[i]->pos = pos;
    mobs[i]->clock = sfClock_create();
    mobs[i]->respawn = sfSeconds(30);
    mobs[i]->hitbox = sfRectangleShape_create();
    mobs[i]->detection = sfCircleShape_create();
    sfCircleShape_setRadius(mobs[i]->detection, 350);
    sfCircleShape_setPosition(mobs[i]->detection, pos);
    mobs[i] = create_sprite(mobs[i]);
    sfRectangleShape_setPosition(mobs[i]->hitbox, mobs[i]->pos);
    sfRectangleShape_setSize(mobs[i]->hitbox, (sfVector2f){50, 50});
    return mobs[i];
}

mobs_t *init_lvl_three(mobs_t **mobs, int i, sfVector2f pos)
{
    mobs[i] = malloc(sizeof(mobs_t));
    mobs[i]->life = 200;
    mobs[i]->id = i;
    mobs[i]->can_collide = 1;
    mobs[i]->level = 3;
    mobs[i]->damages = 30;
    mobs[i]->xp_loot = 60;
    mobs[i]->item_loot = init_loot();
    mobs[i]->pos = pos;
    mobs[i]->clock = sfClock_create();
    mobs[i]->respawn = sfSeconds(30);
    mobs[i]->hitbox = sfRectangleShape_create();
    mobs[i]->detection = sfCircleShape_create();
    sfCircleShape_setRadius(mobs[i]->detection, 400);
    sfCircleShape_setPosition(mobs[i]->detection, pos);
    mobs[i] = create_sprite(mobs[i]);
    sfRectangleShape_setPosition(mobs[i]->hitbox, mobs[i]->pos);
    sfRectangleShape_setSize(mobs[i]->hitbox, (sfVector2f){50, 50});
    return mobs[i];
}

mobs_t *init_lvl_four(mobs_t **mobs, int i, sfVector2f pos)
{
    mobs[i] = malloc(sizeof(mobs_t));
    mobs[i]->life = 250;
    mobs[i]->id = i;
    mobs[i]->can_collide = 1;
    mobs[i]->level = 4;
    mobs[i]->damages = 40;
    mobs[i]->xp_loot = 80;
    mobs[i]->item_loot = init_loot();
    mobs[i]->pos = pos;
    mobs[i]->clock = sfClock_create();
    mobs[i]->respawn = sfSeconds(30);
    mobs[i]->hitbox = sfRectangleShape_create();
    mobs[i]->detection = sfCircleShape_create();
    sfCircleShape_setRadius(mobs[i]->detection, 400);
    sfCircleShape_setPosition(mobs[i]->detection, pos);
    mobs[i] = create_sprite(mobs[i]);
    sfRectangleShape_setPosition(mobs[i]->hitbox, mobs[i]->pos);
    sfRectangleShape_setSize(mobs[i]->hitbox, (sfVector2f){50, 50});
    return mobs[i];
}

mobs_t *init_lvl_boss(mobs_t **mobs, int i, sfVector2f pos)
{
    mobs[i] = malloc(sizeof(mobs_t));
    mobs[i]->life = 1000;
    mobs[i]->id = i;
    mobs[i]->can_collide = 1;
    mobs[i]->level = 5;
    mobs[i]->damages = 60;
    mobs[i]->xp_loot = 300;
    mobs[i]->item_loot = init_loot();
    mobs[i]->pos = pos;
    mobs[i]->clock = sfClock_create();
    mobs[i]->respawn = sfSeconds(45);
    mobs[i]->hitbox = sfRectangleShape_create();
    mobs[i]->detection = sfCircleShape_create();
    sfCircleShape_setRadius(mobs[i]->detection, 300);
    sfCircleShape_setPosition(mobs[i]->detection, pos);
    mobs[i] = create_boss_sprite(mobs[i]);
    sfRectangleShape_setPosition(mobs[i]->hitbox, mobs[i]->pos);
    sfRectangleShape_setSize(mobs[i]->hitbox, (sfVector2f){150, 150});
    return mobs[i];
}
