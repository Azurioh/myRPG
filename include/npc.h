/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** npc
*/

#ifndef INCLUDED_NPC_H
    #define INCLUDED_NPC_H
    #define     FONT "assets/font/alagard.ttf"

    #include <SFML/Graphics.h>

typedef struct npc_info_s {
    sfVector2f pos;
    int is_interact;
    int is_speak;
    sfRectangleShape *rect;
    sfSprite *sprite;
    int id;
} npc_info_t;

typedef struct npc_visual_s {
    sfRectangleShape *rect;
    sfText *text;
} npc_visual_t;

typedef struct npc_s {
    npc_info_t **npc_info;
    npc_visual_t *visual;
    char **all_texts;
    int read;
} npc_t;

void free_npc(npc_t *npc);
void draw_text(npc_t *npc, int i);

#endif
