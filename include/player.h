/*
** EPITECH PROJECT, 2024
** player.h
** File description:
** All struct and functions used to update the player informations
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include <SFML/Graphics.h>
    #include <string.h>
    #include "inventory.h"

typedef struct skills_s {
    char *name;
    int level;
    int unlocked;
    int max_level;
    int is_max_level;
} skills_t;

typedef struct player_interface_s {
    sfSprite *sprite;
    sfVector2f movement;
    float speed;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    float animation_time;
} player_interface_t;

typedef struct player_s {
    char *name;
    int life;
    int is_alive;
    int nb_dead;
    int experience;
    int level;
    int nb_skills_to_upgrade;
    skills_t **skills;
    player_interface_t *interface;
    inventory_t *inventory;
    sfVector2f pos;
} player_t;

player_t *init_player(void);
skills_t **init_player_skills(void);
void free_player(player_t *player);

int update_player_experience(player_t *player, unsigned int amount);
int update_skill(player_t *player, unsigned int skill_index);
int increase_player_life(player_t *player, unsigned int amount);
int decrease_player_life(player_t *player, unsigned int amount);
sfSprite *init_player_sprite(player_interface_t *player_interface);
#endif
