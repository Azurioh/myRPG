/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** speak_npc
*/
#include "../../include/myrpg.h"
#include "../../include/npc.h"

void init_text_for_npc(npc_t *npc)
{
    sfFont *font = sfFont_createFromFile("assets/font/alagard.ttf");

    for (int i = 0; npc->npc_info[i] != NULL; i++) {
        npc->npc_info[i]->text_ig = create_text(npc->
            npc_info[i]->text, 20, npc->npc_info[i]->pos, font);
        sfText_setPosition(npc->npc_info[i]->text_ig, npc->npc_info[i]->pos);
    }
}

void display_npc_text(myrpg_t *myrpg, sfText *text_ig)
{
    sfRenderWindow_drawText(WINDOW, text_ig, NULL);
}
