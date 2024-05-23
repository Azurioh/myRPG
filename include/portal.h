/*
** EPITECH PROJECT, 2024
** myRPG
** File description:
** portal
*/

#ifndef INCLUDED_PORTAL_H
    #define INCLUDED_PORTAL_H
    #include <SFML/Graphics.h>

typedef struct portal_pos_s {
    sfVector2f pos;
    sfVector2f pos_tp;
    sfRectangleShape *rect;
    int is_teleportor;
    int id;
} portal_pos_t;

typedef struct portal_s {
    portal_pos_t **portal_pos;
    int nbr_portal;
} portal_t;

void free_portals(portal_t *portals);
portal_t *portal_map(void);
#endif
