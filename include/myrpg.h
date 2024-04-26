/*
** EPITECH PROJECT, 2024
** myrpg.h
** File description:
** All protos, include and struct for the project
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "player.h"
    #include "game.h"
    #include "button.h"
    #include "events.h"
    #include "generation.h"
    #include "hud.h"
    #include "inventory.h"

typedef struct myrpg_s {
    player_t *player;
    game_t *game_info;
    event_t *list_of_events;
    sfSprite *background;
    button_t **buttons;
    hud_t *hud;
    int can_interact;
} myrpg_t;

int start_game(void);
int loop(myrpg_t *myrpg);
void free_myrpg(myrpg_t *myrpg);
void free_image(image_t *image);

void load_main_menu(myrpg_t *myrpg);
void display_main_menu(myrpg_t *myrpg);
void display_hud(myrpg_t *myrpg);
void display_inventory(myrpg_t *myrpg);
#endif
