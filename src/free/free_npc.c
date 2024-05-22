/*
** EPITECH PROJECT, 2024
** free_npc
** File description:
** Free the npc struct
*/

#include "../../include/myrpg.h"

void free_npc(npc_t *npc)
{
    if (!npc) {
        return;
    }
    free(npc);
}
