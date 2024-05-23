/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** npc
*/

#ifndef INCLUDED_NPC_H
    #define INCLUDED_NPC_H
    #define     FONT "../../assets/font/alagard.ttf"
    #include <SFML/Graphics.h>

typedef struct npc_info_s {
    sfVector2f pos;
    int is_interact;
    int is_speak;
    sfRectangleShape *rect;
    char *text;
    sfSprite *sprite;
    int id;
    sfText *text_ig;
} npc_info_t;

typedef struct npc_s {
    npc_info_t **npc_info;
    sfIntRect rect;
} npc_t;

void free_npc(npc_t *npc);
void draw_text(npc_t *npc, int i);

#endif
