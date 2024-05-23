/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** interract_npc
*/
#include "../../include/myrpg.h"
#include "../../include/npc.h"

int detect_npc(myrpg_t *myrpg, int i)
{
    myrpg->player->pos = sfView_getCenter(myrpg->game_info->map_view);
    if (myrpg->player->pos.x >= myrpg->npc->npc_info[i]->pos.x - 50 &&
        myrpg->player->pos.x <= myrpg->npc->npc_info[i]->pos.x + 50 &&
        myrpg->player->pos.y >= myrpg->npc->npc_info[i]->pos.y - 50 &&
        myrpg->player->pos.y <= myrpg->npc->npc_info[i]->pos.y + 50) {
        return i;
    }
    return -1;
}

static int can_speak2(myrpg_t *myrpg, int i)
{
    if (detect_npc(myrpg, i) != -1) {
        myrpg->can_interact = 1;
        if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->interact)) {
            display_npc_text(myrpg, myrpg->npc->npc_info[i]->text_ig);
        }
    }
    return 0;
}

int can_speak(myrpg_t *myrpg, npc_t *npc)
{
    for (int i = 0; npc->npc_info[i] != NULL; i++) {
        can_speak2(myrpg, i);
    }
    return -1;
}
