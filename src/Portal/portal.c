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
    sfVector2f pos = sfView_getCenter(myrpg->game_info->map_view);
    if (pos.x >= portal->portal_pos[i]->pos.x &&
        pos.x <= portal->portal_pos[i]->pos.x + 100 &&
        pos.y >= portal->portal_pos[i]->pos.y && pos.y <=
        portal->portal_pos[i]->pos.y + 100) {
            myrpg->can_interact = 1;
            return i;
    } else {
        myrpg->can_interact = 0;
    }
    return -1;
}

void teleport(player_t *player, portal_t *portal, int i, myrpg_t *myrpg)
{
    if (coord_portal(player, portal, myrpg, i) != -1 &&
    portal->portal_pos[i]->is_teleportor == 1 && sfKeyboard_isKeyPressed(myrpg->game_info->keybinds->interact)) {
        player->pos.x = portal->portal_pos[i]->pos_tp.x;
        player->pos.y = portal->portal_pos[i]->pos_tp.y;
            set_all_after_tp(myrpg, portal->portal_pos[i]->pos_tp);
    }
}

static portal_pos_t **fill_struct_portal_map(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *) * 3);
    sfVector2f portal_0 = {5000, 5000};
    sfVector2f portal_1 = {4500, 4500};

    for (int i = 0; i < 2; i++) {
        portal_pos[i] = malloc(sizeof(portal_pos_t));
    }
    portal_pos[0]->pos = portal_0;
    portal_pos[1]->pos = portal_1;
    portal_pos[2] = NULL;
    for (int i = 0; i < 2; i++) {
        portal_pos[i]->id = i;
    }
    return portal_pos;
}

static void fill_struct_portal_isteleportor_map(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 1;
    portal->portal_pos[1]->is_teleportor = 1;
}

static void create_rectangle_collision_map(portal_t *portal)
{
    sfVector2f scale = {100, 100};

    for (int i = 0; i < 2; i++) {
        portal->portal_pos[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(portal->portal_pos[i]->rect,
            portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(portal->portal_pos[i]->rect, sfBlack);
    }
}

portal_t *portal_map(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_map();
    fill_struct_portal_isteleportor_map(portal);
    create_rectangle_collision_map(portal);
    link_portal(portal, 0, 1);
    return portal;
}

void check_portal(myrpg_t *myrpg)
{
    for (int i = 0; myrpg->portal->portal_pos[i] != NULL; i++) {
        teleport(myrpg->player, myrpg->portal, i, myrpg);
    }
}