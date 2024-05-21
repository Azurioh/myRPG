/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** speak_npc
*/
#include "../../include/myrpg.h"
#include "../../include/npc.h"

void draw_text(npc_t *npc, int i)
{
    create_text(npc->npc_info[i]->text, 10, npc->npc_info[i]->pos, FONT);
}
