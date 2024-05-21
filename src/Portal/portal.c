/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** portal
*/
#include "../../include/portal.h"
#include "../../include/player.h"
#include "../../include/game.h"
#include "../../include/myrpg.h"

void link_portal(portal_t *portal, int src, int dest)
{
    portal->portal_pos[src]->pos_tp = portal->portal_pos[dest]->pos;
}

int coord_portal(player_t *player, portal_t *portal, myrpg_t *myrpg, int i)
{
    player->pos = sfView_getCenter(myrpg->game_info->map_view);
    if (player->pos.x >= portal->portal_pos[i]->pos.x &&
        player->pos.x <= portal->portal_pos[i]->pos.x + 144 &&
        player->pos.y >= portal->portal_pos[i]->pos.y && player->pos.y <=
        portal->portal_pos[i]->pos.y + 96) {
        return i;
    }
    return -1;
}

void teleport(player_t *player, portal_t *portal, int i, myrpg_t *myrpg)
{
    if (coord_portal(player, portal, myrpg, i) != -1 &&
    portal->portal_pos[i]->is_teleportor != 0) {
        player->pos.x = portal->portal_pos[i]->pos_tp.x;
        player->pos.y = portal->portal_pos[i]->pos_tp.y;
        sfSprite_setPosition(myrpg->game_info->player, player->pos);
    }
}

static portal_pos_t **fill_struct_portal_map(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *)*3);
    sfVector2f pos_bin_0 = {5000, 5000};
    sfVector2f pos_bin_1 = {6000, 6000};

    for (int i = 0; i < 2; i++) {
        portal_pos[i] = malloc(sizeof(portal_pos_t));
    }
    portal_pos[0]->pos = pos_bin_0;
    portal_pos[1]->pos = pos_bin_1;
    portal_pos[2] = NULL;
    for (int i = 0; i < 2; i++) {
        portal_pos[i]->id = i;
    }
    return portal_pos;
}

static void fill_struct_portal_isteleportor_map(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 1;
    portal->portal_pos[1]->is_teleportor = 0;
}

static void create_rectangle_colision_map(portal_t *portal)
{
    sfVector2f scale = {144, 96};

    for (int i = 0; i < 2; i++) {
        portal->portal_pos[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(portal->portal_pos[i]->rect,
            portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(portal->portal_pos[i]->rect, sfWhite);
    }
}

portal_t *portal_map(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_map();
    fill_struct_portal_isteleportor_map(portal);
    create_rectangle_colision_map(portal);
    link_portal(portal, 0, 1);
    return portal;
}
