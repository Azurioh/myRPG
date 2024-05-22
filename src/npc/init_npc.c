/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** init_npc
*/

#include "../../include/npc.h"
#include "../../include/generation.h"
#include "../../include/myrpg.h"

sfSprite *init_npc()
{
    sfSprite *npc = generate_sprite_with_file(PLAYER_PATH);
    sfVector2f place_npc = {7900, 4800};

    sfSprite_setPosition(npc, place_npc);

    return npc;
}