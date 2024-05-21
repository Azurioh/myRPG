/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** npc
*/

#ifndef INCLUDED_NPC_H
    #define INCLUDED_NPC_H
    #include "myrpg.h"

typedef struct npc_info_s {
    sfVector2f pos;
    int is_interact;
    int is_speak;
    sfRectangleShape *rect;
    char *text;
} npc_info_t;

typedef struct npc_s {
    npc_info_t **npc_info

} npc_t;

// void spawn_npc(image_t *image, myrpg_t *myrpg);

#endif
