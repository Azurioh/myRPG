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
    #define EVENTS myrpg->list_of_events
    #define BUTTONS myrpg->buttons
    #define SCALING myrpg->settings->scaling

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "player.h"
    #include "game.h"
    #include "button.h"
    #include "events.h"
    #include "generation.h"
    #include "settings.h"

typedef struct myrpg_s {
    player_t *player;
    game_t *game_info;
    event_t *list_of_events;
    sfSprite *background;
    button_t **buttons;
    settings_t *settings;
} myrpg_t;

int start_game(void);
int loop(myrpg_t *myrpg);
void free_myrpg(myrpg_t *myrpg);

sfText *init_text(char *txt, sfVector2f position, unsigned int size,
    sfColor color);
void load_main_menu(myrpg_t *myrpg);

button_t **load_settings_buttons(settings_t *settings);
sfText **load_settings_texts(settings_t *settings);

void manage_button_event(button_t **buttons, myrpg_t *myrpg);
void animate_button(button_t *button, settings_t *setting);

char *my_nbr_to_str(int nb);
#endif
