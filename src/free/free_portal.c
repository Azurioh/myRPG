/*
** EPITECH PROJECT, 2024
** free_portal
** File description:
** Free the portal struct
*/

#include "../../include/myrpg.h"
#include "SFML/Graphics/Types.h"

static void free_portal(portal_pos_t *portal)
{
    if (!portal) {
        return;
    }
    sfRectangleShape_destroy(portal->rect);
    free(portal);
}

void free_portals(portal_t *portals)
{
    if (!portals) {
        return;
    }
    for (int i = 0; portals->portal_pos[i]; i++) {
        free_portal(portals->portal_pos[i]);
    }
    free(portals);
}
