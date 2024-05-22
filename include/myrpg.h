/*
** EPITECH PROJECT, 2024
** myrpg.h
** File description:
** All protos, include and struct for the project
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "player.h"
    #include "game.h"
    #include "button.h"
    #include "events.h"
    #include "generation.h"
    #include "hud.h"
    #include "inventory.h"
    #include "move.h"
    #include "portal.h"
    #include "npc.h"

typedef struct myrpg_s {
    player_t *player;
    game_t *game_info;
    event_t *list_of_events;
    sfSprite *background;
    button_t **buttons;
    portal_t *portal;
    hud_t *hud;
    npc_t *npc;
    int can_interact;
    int is_inventory;
} myrpg_t;

int start_game(void);
int loop(myrpg_t *myrpg);
int check_events(myrpg_t *myrpg);
void free_myrpg(myrpg_t *myrpg);
void free_image(image_t *image);

void move(myrpg_t *myrpg);
void move_down_view(game_t *game_info, myrpg_t *myrpg);
void move_up_view(game_t *game_info, myrpg_t *myrpg);
void move_left_view(game_t *game_info, myrpg_t *myrpg);
void move_right_view(game_t *game_info, myrpg_t *myrpg);

void load_main_menu(myrpg_t *myrpg);
void display_main_menu(myrpg_t *myrpg);
void display_hud(myrpg_t *myrpg);
void display_inventory(myrpg_t *myrpg);


// PORTAL
void teleport(player_t *player, portal_t *portal, int i, myrpg_t *myrpg);
void check_portal(myrpg_t *myrpg);

// NPC
void spawn_npc(myrpg_t *myrpg);
sfSprite *init_npc();
#endif
