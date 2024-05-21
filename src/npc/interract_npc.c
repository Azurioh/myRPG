/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** interract_npc
*/
#include "../../include/myrpg.h"
#include "../../include/npc.h"

int detect_npc(player_t *player, npc_t *npc, myrpg_t *myrpg, int i)
{
    player->pos = sfView_getCenter(myrpg->game_info->map_view);
    if(player->pos.x >= npc->npc_info[i]->pos.x &&
        player->pos.x <= npc->npc_info[i]->pos.x + 50 &&
        player->pos.y >= npc->npc_info[i]->pos.y && player->pos.y <=
        npc->npc_info[i]->pos.y + 20) {
        return i;
    }
    return -1;
}

void can_speak(myrpg_t *myrpg,  npc_t *npc, int i)
{
    for (int i = 0; i != NULL; i++) {
        if (myrpg->can_interact == 1) {
            draw_text(npc, detect_npc(myrpg->player, npc, myrpg, i));
        }
    }
}