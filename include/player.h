/*
** EPITECH PROJECT, 2024
** player.h
** File description:
** All struct and functions used to update the player informations
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include <SFML/Graphics.h>

typedef struct skills_s {
    char *name;
    int level;
    int max_level;
} skills_t;

typedef struct player_interface_s {
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    float animation_time;
} player_interface_t;

typedef struct player_s {
    int life;
    int experience;
    int level;
    skills_t *skills;
    player_interface_t *interface;
} player_t;

#endif

