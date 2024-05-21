/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** init_text
*/
#include "../../include/npc.h"

static void stock_text_npc_0(npc_t *npc)
{
    npc->npc_info[0]->text = "text du npc n°1";
}

static void stock_text_npc_1(npc_t *npc)
{
    npc->npc_info[1]->text = "text du npc n°2";
}

static void stock_text_npc_2(npc_t *npc)
{
    npc->npc_info[2]->text = "text du npc n°3";
}

void stock_text_in_npc(npc_t *npc)
{
    stock_text_npc_0(npc);
    stock_text_npc_1(npc);
    stock_text_npc_2(npc);
}