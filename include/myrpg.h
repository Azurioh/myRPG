/*
** EPITECH PROJECT, 2024
** myrpg.h
** File description:
** All protos, include and struct for the project
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #define PLAYER myrpg->player
    #define GAME_INFO myrpg->game_info
    #define SETTINGS myrpg->settings
    #define EVENTS myrpg->events
    #define BUTTONS myrpg->buttons
    #define SCALING myrpg->settings->scaling
    #define WINDOW SETTINGS->window

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "player.h"
    #include "game.h"
    #include "button.h"
    #include "events.h"
    #include "generation.h"
    #include "settings.h"
    #include "hud.h"
    #include "inventory.h"
    #include "move.h"

typedef struct myrpg_s {
    int game_open;
    player_t *player;
    game_t *game_info;
    event_t *events;
    sfSprite *background;
    button_t **buttons;
    settings_t *settings;
    hud_t *hud;
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
void display_inventory(myrpg_t *myrpg);
void display_hud(myrpg_t *myrpg);

sfText *init_text(char *txt, sfVector2f position, unsigned int size,
    sfColor color);

button_t **load_settings_buttons(settings_t *settings);
sfText **load_settings_texts(settings_t *settings);

void manage_button_event(button_t **buttons, myrpg_t *myrpg);
void animate_button(button_t *button);

char *my_nbr_to_str(int nb);
char *my_strcat(char *dest, char const *str);
#endif
