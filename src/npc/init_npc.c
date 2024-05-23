/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** init_npc
*/

#include "../../include/npc.h"
#include "../../include/generation.h"
#include "../../include/myrpg.h"


sfSprite *init_npc_sprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(PLAYER_PATH, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

static void create_npc_collision_npc(npc_t *npc)
{
    sfVector2f scale = {100, 100};

    for (int i = 0; i < 5; i++) {
        npc->npc_info[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(npc->npc_info[i]->rect, scale);
        sfRectangleShape_setPosition(npc->npc_info[i]->rect,
            npc->npc_info[i]->pos);
        sfRectangleShape_setFillColor(npc->npc_info[i]->rect, sfBlack);
    }
}

static npc_info_t **fill_struct_npc(void)
{
    npc_info_t **npc_info = malloc(sizeof(npc_info_t *) * 6);

    if (!npc_info)
        return NULL;
    for (int i = 0; i < 5; i++) {
        npc_info[i] = malloc(sizeof(npc_info_t));
    }
    npc_info[0]->pos = (sfVector2f) {5000, 5000};
    npc_info[1]->pos = (sfVector2f) {5200, 5200};
    npc_info[2]->pos = (sfVector2f) {5400, 5400};
    npc_info[3]->pos = (sfVector2f) {5600, 5600};
    npc_info[4]->pos = (sfVector2f) {5800, 5800};
    npc_info[5] = NULL;
    for (int i = 0; i < 5; i++) {
        npc_info[i]->id = i;
    }
    return npc_info;
}

npc_t *init_npc(void)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->npc_info = fill_struct_npc();
    for (int i = 0; npc->npc_info[i] != NULL; i++) {
        npc->npc_info[i]->sprite = init_npc_sprite();
    }
    create_npc_collision_npc(npc);
    return npc;
}
