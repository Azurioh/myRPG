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
    portal->portal_pos[dest]->pos_tp = portal->portal_pos[src]->pos;
}

int coord_portal(portal_t *portal, myrpg_t *myrpg, int i)
{
    sfVector2f pos = sfView_getCenter(myrpg->game_info->map_view);

    if (pos.x + 16 >= portal->portal_pos[i]->pos.x &&
        pos.x + 16 <= portal->portal_pos[i]->pos.x + 150 &&
        pos.y + 64 >= portal->portal_pos[i]->pos.y && pos.y  + 64 <=
        portal->portal_pos[i]->pos.y + 150) {
            myrpg->can_interact = 1;
            return i;
        }
    return -1;
}

int teleport(portal_t *portal, int i, myrpg_t *myrpg)
{
    if (coord_portal(portal, myrpg, i) != -1) {
        myrpg->can_interact = 1;
        if (sfKeyboard_isKeyPressed(GAME_INFO->keybinds->interact)) {
            myrpg->transition_state = 0;
            move_all_after_tp(myrpg, portal->portal_pos[i]->pos_tp);
        }
        return 0;
    }
    return -1;
}

static portal_pos_t **fill_struct_portal_map(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *) * 9);

    for (int i = 0; i < 8; i++) {
        portal_pos[i] = malloc(sizeof(portal_pos_t));
    }
    portal_pos[0]->pos = (sfVector2f) {4050, 5320};
    portal_pos[1]->pos = (sfVector2f) {2543, 692};
    portal_pos[2]->pos = (sfVector2f) {4950, 4930};
    portal_pos[3]->pos = (sfVector2f) {4108, 575};
    portal_pos[4]->pos = (sfVector2f) {500, 2450};
    portal_pos[5]->pos = (sfVector2f) {4580, 4550};
    portal_pos[6]->pos = (sfVector2f) {5975, 3273};
    portal_pos[7]->pos = (sfVector2f) {687, 622};
    portal_pos[8] = NULL;
    for (int i = 0; i < 6; i++) {
        portal_pos[i]->id = i;
    }
    return portal_pos;
}

static void create_rectangle_collision_map(portal_t *portal)
{
    sfVector2f scale = {150, 150};

    for (int i = 0; i < 8; i++) {
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
    create_rectangle_collision_map(portal);
    link_portal(portal, 0, 1);
    link_portal(portal, 2, 3);
    link_portal(portal, 4, 5);
    link_portal(portal, 6, 7);
    return portal;
}

bool check_portal(myrpg_t *myrpg)
{
    for (int i = 0; myrpg->portal->portal_pos[i] != NULL; i++) {
        if (teleport(myrpg->portal, i, myrpg) == 0) {
            return true;
        }
    }
    myrpg->can_interact = 0;
    return false;
}
