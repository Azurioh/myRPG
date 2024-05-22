/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** spawn_npc
*/
#include "../../include/npc.h"
#include "../../include/generation.h"
#include "../../include/myrpg.h"

void spawn_npc(myrpg_t *myrpg)
{
    for (int i = 0; myrpg->npc->npc_info[i] != NULL; i++) {
        sfRenderWindow_drawSprite(myrpg->settings->window,
            myrpg->npc->npc_info[i]->sprite, NULL);
    }
}
