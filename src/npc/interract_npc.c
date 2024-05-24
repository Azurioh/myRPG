/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** interract_npc
*/
#include "../../include/myrpg.h"
#include "../../include/npc.h"
#include "SFML/Window/Keyboard.h"

int detect_npc(player_t *player, npc_t *npc, myrpg_t *myrpg, int i)
{
    player->pos = sfView_getCenter(myrpg->game_info->map_view);
    if (player->pos.x >= npc->npc_info[i]->pos.x &&
        player->pos.x <= npc->npc_info[i]->pos.x + 50 &&
        player->pos.y >= npc->npc_info[i]->pos.y && player->pos.y <=
        npc->npc_info[i]->pos.y + 20) {
        return i;
    }
    return -1;
}

static bool check_npc_collision(myrpg_t *myrpg, npc_info_t *info)
{
    if (PLAYER->pos.x >= info->pos.x - 50
        && PLAYER->pos.x <= info->pos.x + 50
        && PLAYER->pos.y >= info->pos.y - 50
        && PLAYER->pos.y <= info->pos.y + 50) {
        return true;
    }
    return false;
}

static bool check_npc(myrpg_t *myrpg, npc_info_t *info)
{
    if (check_npc_collision(myrpg, info)) {
        myrpg->can_interact = 1;
        if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->interact) == true) {
            display_npc(myrpg);
        }
        return true;
    }
    return false;
}

void can_speak(myrpg_t *myrpg, npc_t *npc)
{
    for (int i = 0; npc->npc_info[i] != NULL; i++) {
        if (check_npc(myrpg, npc->npc_info[i]) == true)
            return;
    }
    myrpg->can_interact = 0;
}
